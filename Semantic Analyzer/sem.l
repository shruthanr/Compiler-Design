alpha [A-Za-z]
digit [0-9]


%%
"<="		                                                    return LE;
"<"                                                             return LT;
">="                                                            return GE;
">"                                                             return GT;
"++"                                                            return INCR;
"--"                                                            return DECR;
"=="                                                            return EQUAL;
"%"                                                             return MOD;

[ \t]                                                                      ;
\n	{yylineno++                                                            ;}

"{"	{block_start(); return '{';}
"}"	{block_end(); return '}';}

"int"	{yylval.ival = INT;                                     return INT;}
"float"	{yylval.ival = FLOAT;                                   return FLOAT;}
"void"	{yylval.ival = VOID; return VOID;}
"unsigned int" {yylval.ival = UNSIGNED_INT;                     return UNSIGNED_INT;}
"long int" {yylval.ival = L_INT;                                return L_INT;}
"short int" {yylval.ival = S_INT;                               return S_INT;}
"else"	{return ELSE;}
"if"	return IF;
"while"	                                                        return WHILE;
"for"                                                           return FOR;
"return" 	                                                    return RETURN;
"printf"	                                                    return PRINT;

^"#include ".+	                                                return PREPROC;

{alpha}({alpha}|{digit})* {yylval.str=strdup(yytext);           return ID;}
{digit}+	{yylval.str=strdup(yytext);                         return INT_CONST;}
{digit}+\.{digit}+ 	{yylval.str=strdup(yytext);                 return FLOAT_CONST;}

\/\/.*                                                                            ;
\/\*(.*\n)*.*\*\/                                                                 ;

\".*\"	                                                        return STRING;
.	                                                            return yytext[0];
%%