%{
    #include<stdio.h>
    #include<string.h>
	#include <stdlib.h>
	int btop = -1;
	int nested_comment_stack = 0;
	int line = 0;
	char bstack[100];
	struct hashtable{
    char name[100];
    char type[100];
    int len;
}table[1000];
%}
%x comment

LEQ <=
GEQ >=
EQ =
LES <
GRE >
PLUS \+
INCREMENT \+\+
DECREMENT \-\-
MINUS \-
MULT \*
DIV \/
REM %
AND &
OR \|
XOR \^
NOT \~

PREPROCESSOR #(include<.*>|define.*|ifdef|endif|if|else|ifndef|undef|pragma)
STRING \".*\"|\'.*\'
WRONG_STRING \"[^"\n]*|\'[^'\n]* 
SINGLELINE \/\/.*
MULTILINE "/*"([^*]|\*+[^*/])*\*+"/"
KEYWORD auto|const|default|enum|extern|register|return|sizeof|static|struct|typedef|union|volatile|break|continue|goto|else|switch|if|case|default|for|do|while|char|double|float|int|long|short|signed|unsigned|void
IDENTIFIER [a-zA-Z_]([a-zA-Z0-9_])*
NUMBER_CONSTANT [1-9][0-9]*(\.[0-9]+)?|0(\.[0-9]+)? 
OPERATOR {INCREMENT}|{DECREMENT}|{PLUS}|{MINUS}|{MULT}|{DIV}|{EQ}
COMPARISON {LEQ}|{GEQ}|{LES}|{GRE}
BITWISE {XOR}|{REM}|{AND}|{OR}|{NOT}
INVALID [^\n\t ]
WRONG_ID ([0-9\*\-\+\%\/]+[a-zA-Z][a-zA-Z0-9\*\-\+\%\/]*)


%%
\n line++;
[\t ] ;
; {printf("%s \t---- SEMICOLON DELIMITER\n", yytext);}
, {printf("%s \t---- COMMA DELIMITER\n", yytext);}
\{ {printf("%s \t---- PARENTHESIS\n", yytext);
	if(btop==-1){
		bstack[0]='{'; btop=1;}
	else {bstack[btop]='{';
	btop++;
    }
	}
\} {printf("%s \t---- PARENTHESIS\n", yytext);
	if(bstack[btop-1]!='{')
		printf("ERROR: UNBALANCED PARENTHESIS AT LINE NUMBER: %d\n",line);
	btop--;
	}
\( {printf("%s \t---- PARENTHESIS\n", yytext);
	if(btop==-1){
		bstack[0]='('; btop=1;}
	else {
        bstack[btop]='(';
    	btop++;
    }
	}
\) {printf("%s \t---- PARENTHESIS\n", yytext);
	if(bstack[btop-1]!='(')
		printf("ERROR: UNBALANCED PARENTHESIS AT LINE NUMBER: %d\n",line);
	btop--;
	}
\[ {printf("%s \t---- PARENTHESIS\n", yytext);
	if(btop==-1){
		bstack[0]='['; btop=1;}
	else {
        bstack[btop]='[';
    	btop++;
    }
	}
\] {printf("%s \t---- PARENTHESIS\n", yytext);
	if(bstack[btop-1]!='[')
		printf("ERROR: UNBALANCED PARENTHESIS AT LINE NUMBER: %d\n",line);
	btop--;
	}
\\ {printf("%s \t- FSLASH\n", yytext);}
\. {printf("%s \t- DOT DELIMITER\n", yytext);}

"/*"                    {
						BEGIN(comment); 
						nested_comment_stack=1; 
						yymore();
						}
<comment><<EOF>>        {printf("\nERROR: MULTILINE COMMENT: \""); yyless(yyleng-2); ECHO; printf("\", NOT TERMINATED AT LINE NUMBER: %d",line); yyterminate();}
<comment>"/*"           {nested_comment_stack++; yymore();}
<comment>.              {yymore();}
<comment>\n             {yymore();line++;}
<comment>"*/"           {nested_comment_stack--;
                        if(nested_comment_stack<0)
                        {
                          printf("\n \"%s\"\t---- ERROR: UNBALANCED COMMENT AT LINE NUMBER: %d.", yytext, line);
                          yyterminate();
                        }
                        else if(nested_comment_stack==0)
                        {
                          BEGIN(INITIAL);
                        }
                        else
                          yymore();
                        }

"*/"                    {printf("%s \t---- ERROR: UNINITIALISED COMMENT AT LINE NUMBER: %d\n", yytext,line); yyterminate();}

"//".*                  {printf("%s \t---- SINGLE LINE COMMENT\n", yytext);}

{PREPROCESSOR} printf("%s \t---- PREPROCESSOR\n", yytext);
{STRING} {printf("%s \t---- STRING \n", yytext); insert_symbol(yytext,"STRING CONSTANT");}
{MULTILINE} {printf("%s \t---- MULTI LINE COMMENT\n", yytext);}
{KEYWORD} {printf("%s \t---- KEYWORD\n", yytext); insert_symbol(yytext, "KEYWORD");}
{IDENTIFIER} {printf("%s \t---- IDENTIFIER\n", yytext); insert_symbol(yytext, "IDENTIFIER");}
{WRONG_ID} {printf("%s \t---- ERROR: ILL-FORMED IDENTIFIER\n", yytext);}
{NUMBER_CONSTANT} {printf("%s \t---- NUMBER CONSTANT\n", yytext); insert_symbol(yytext, "NUMBER CONSTANT");}
{OPERATOR} {printf("%s \t---- ARITHMETIC OPERATOR\n", yytext);} 
{BITWISE} {printf("%s \t---- BITWISE OPERATOR\n", yytext);}
{COMPARISON} {printf("%s \t---- COMPARISON OPERATOR\n", yytext);}
{WRONG_STRING} {printf("%s \t---- ERROR: UNTERMINATED STRING AT LINE NUMBER: %d\n", yytext,line);}
{INVALID} {printf("%s \t---- ERROR: ILL-FORMED IDENTIFIER AT LINE NUMBER: %d\n", yytext,line); }

%%

int yywrap(){
    return 1;
}