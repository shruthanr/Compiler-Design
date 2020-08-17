%{
    #include<stdio.h>
    #include<string.h>
	#include <stdlib.h>

    struct hashtable {
        char name[100];
        char type[100];
        int len;
    } table[1000];

	int btop = -1;
	int nested_comment_stack = 0;
	int line = 0;
	char bstack[100];
	
    
%}
%x comment

Preprocessor #(include<.*>|define.*|ifdef|endif|if|else|ifndef|undef|pragma)
String \".*\"|\'.*\'
InvalidString \"[^"\n]*|\'[^'\n]* 
SINGLELINE \/\/.*
MultiLineComment "/*"([^*]|\*+[^*/])*\*+"/"
Keyword auto|const|default|enum|extern|register|return|sizeof|static|struct|typedef|union|volatile|break|continue|goto|else|switch|if|case|default|for|do|while|char|double|float|int|long|short|signed|unsigned|void
Identifier [a-zA-Z_]([a-zA-Z0-9_])*
NumericConstant [1-9][0-9]*(\.[0-9]+)?|0(\.[0-9]+)? 
ArithmeticOperator \+\+|\-\-|\+|\-|\*|\/|=
ComparisionOperator <=|>=|<|>
BitwiseOperator \^|\%|\&|\||\~
InvalidID [^\n\t ]
InvalidIdentifier ([0-9\*\-\+\%\/]+[a-zA-Z][a-zA-Z0-9\*\-\+\%\/]*)


%%
\n line++;
[\t ] ;
; {printf("%s \t---- Semicolon Delimiter\n", yytext);}
, {printf("%s \t---- Comma Delimiter\n", yytext);}

\{ {
    printf("%s \t---- Parenthesis\n", yytext);
	if (btop == -1){
		bstack[0]='{'; btop=1;} 
	else {
        bstack[btop]='{';
	    btop++;
    }
}
\} {
    printf("%s \t---- Parenthesis\n", yytext);
	if(bstack[btop-1] != '{')
		printf("ERROR: Unbalanced parenthesis at line number: %d\n",line);
	btop--;
}
\( {
    printf("%s \t---- Parenthesis\n", yytext);
	if(btop == -1){
		bstack[0] = '('; 
        btop=1;
    }
	else {
        bstack[btop]='(';
    	btop++;
    }
}
\) {
    printf("%s \t---- Parenthesis\n", yytext);
	if(bstack[btop-1] != '(')
		printf("ERROR: UNBALANCED PARENTHESIS AT LINE NUMBER: %d\n",line);
	btop--;
}

\[ {
    printf("%s \t---- Parenthesis\n", yytext);
	if (btop == -1){
		bstack[0]='['; 
        btop=1;
    }
	else {
        bstack[btop]='[';
    	btop++;
    }
}

\] {
    printf("%s \t---- Parenthesis\n", yytext);
	if (bstack[btop-1] != '[')
		printf("ERROR: UNBALANCED PARENTHESIS AT LINE NUMBER: %d\n",line);
	btop--;
}
\\ {
    printf("%s \t- Forward Slash\n", yytext);
}
\. {
    printf("%s \t- Dot Delimiter\n", yytext);
}

"/*" {
    BEGIN(comment); 
    nested_comment_stack=1; 
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
    nested_comment_stack++; 
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
    nested_comment_stack--;
    if(nested_comment_stack<0)
    {
        printf("\n \"%s\"\t---- ERROR: Unbalanced comment at line: %d.", yytext, line);
        yyterminate();
    }
    else if(nested_comment_stack==0)
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
    insert_symbol(yytext,"String Constant");
}
{MultiLineComment} {
    printf("%s \t---- Multi-Line Comment\n", yytext);
}
{Keyword} {
    printf("%s \t---- Keyword\n", yytext); 
    insert_symbol(yytext, "Keyword");
}
{Identifier} {
    printf("%s \t---- Identifier\n", yytext); 
    insert_symbol(yytext, "Identifier");
}
{InvalidIdentifier} {
    printf("%s \t---- ERROR: Invalid Identifier\n", yytext);
}
{NumericConstant} {
    printf("%s \t---- Numeric Constant\n", yytext); 
    insert_symbol(yytext, "Numeric Constant");
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