%{
    #include<stdio.h>
    #include<string.h>
	#include <stdlib.h>

    int stackTop = 0;
	int nestedCommentStack = 0;
	int line = 0;
	char parenthesisStack[100];
	
    
%}
%x comment

Preprocessor #(include<.*>|define.*|ifdef|endif|if|else|ifndef|undef|pragma)
ArithmeticOperator \+\+|\-\-|\+|\-|\*|\/|=
ComparisionOperator <=|>=|<|>
BitwiseOperator \^|\%|\&|\||\~
Identifier [a-zA-Z_]([a-zA-Z0-9_])*
NumericConstant [1-9][0-9]*(\.[0-9]+)?|0(\.[0-9]+)? 
String \".*\"|\'.*\'
InvalidString \"[^"\n]*|\'[^'\n]* 
SingleLineComment \/\/.*
MultiLineComment "/*"([^*]|\*+[^*/])*\*+"/"
Keyword auto|const|default|enum|extern|register|return|sizeof|static|struct|typedef|union|volatile|break|continue|goto|else|switch|if|case|default|for|do|while|char|double|float|int|long|short|signed|unsigned|void
InvalidID [^\n\t ]
InvalidIdentifier ([0-9\*\-\+\%\/]+[a-zA-Z][a-zA-Z0-9\*\-\+\%\/]*)


%%
\n line++;
[\t ] ;
; {printf("%s \t---- Semicolon Delimiter\n", yytext);}
, {printf("%s \t---- Comma Delimiter\n", yytext);}

\{ {
    printf("%s \t---- Parenthesis\n", yytext);
    parenthesisStack[stackTop]='{';
	stackTop++;
   
}
\} {
    printf("%s \t---- Parenthesis\n", yytext);
	if(stackTop == 0 || parenthesisStack[stackTop-1] != '{')
		printf("ERROR: Unbalanced parenthesis at line number: %d\n",line);
	stackTop--;
}
\( {
    printf("%s \t---- Parenthesis\n", yytext);
	parenthesisStack[stackTop]='(';
    stackTop++;
}
\) {
    printf("%s \t---- Parenthesis\n", yytext);
	if(stackTop == 0 || parenthesisStack[stackTop-1] != '(')
		printf("ERROR: UNBALANCED PARENTHESIS AT LINE NUMBER: %d\n",line);
	stackTop--;
}

\[ {
    printf("%s \t---- Parenthesis\n", yytext);
	parenthesisStack[stackTop]='[';
    stackTop++;
}

\] {
    printf("%s \t---- Parenthesis\n", yytext);
	if (stackTop == 0 || parenthesisStack[stackTop-1] != '[')
		printf("ERROR: UNBALANCED PARENTHESIS AT LINE NUMBER: %d\n",line);
	stackTop--;
}
\\ {
    printf("%s \t- Backward Slash\n", yytext);
}
\. {
    printf("%s \t- Dot Delimiter\n", yytext);
}


"/*" {
    BEGIN(comment); 
    nestedCommentStack=1; 
    yymore();
}
<comment><<EOF>> {
    printf("\nERROR: Multiline Comment: \""); 
    yyless(yyleng-2); 
    ECHO; 
    printf("\", Doesn't terminate at line: %d",line); 
    yyterminate();
}
<comment>"/*" {
    nestedCommentStack++; 
    yymore();
}
<comment>. {
    yymore();
}
<comment>\n {
    yymore();
    line++;
}
<comment>"*/" {
    nestedCommentStack--;
    if(nestedCommentStack<0)
    {
        printf("\n \"%s\"\t---- ERROR: Unbalanced comment at line: %d.", yytext, line);
        yyterminate();
    }
    else if(nestedCommentStack==0)
    {
        BEGIN(INITIAL);
    }
    else
        yymore();
}

"*/"    {
    printf("%s \t---- ERROR: Unintialized comment at line: %d\n", yytext,line); 
    yyterminate();
}

"//".*  {
    printf("%s \t---- Single line comment\n", yytext);
}

{Preprocessor} {
    printf("%s \t---- Preprocessor Directive\n", yytext);
}
{String} {
    printf("%s \t---- String \n", yytext); 
    insertToken(yytext,"String Constant");
}
{MultiLineComment} {
    printf("%s \t---- Multi-Line Comment\n", yytext);
}
{Keyword} {
    printf("%s \t---- Keyword\n", yytext); 
    insertToken(yytext, "Keyword");
}
{Identifier} {
    printf("%s \t---- Identifier\n", yytext); 
    insertToken(yytext, "Identifier");
}
{InvalidIdentifier} {
    printf("%s \t---- ERROR: Invalid Identifier\n", yytext);
}
{NumericConstant} {
    printf("%s \t---- Numeric Constant\n", yytext); 
    insertToken(yytext, "Numeric Constant");
}
{ArithmeticOperator} {
    printf("%s \t---- Arithmetic\n", yytext);
} 
{BitwiseOperator} {
    printf("%s \t---- Bitwise Operator\n", yytext);
}
{ComparisionOperator} {
    printf("%s \t---- Comparision Operator\n", yytext);
}
{InvalidString} {
    printf("%s \t---- ERROR: Unterminated string at line number: %d\n", yytext,line);
}
{InvalidID} {
    printf("%s \t---- ERROR: Invalid identifier at line number: %d\n", yytext,line);
}
%%

int yywrap(){
    return 1;
}