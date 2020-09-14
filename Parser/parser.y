%{
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

char type[100];
char temp[100];
%}

%nonassoc NO_ELSE
%nonassoc ELSE
%left '<' '>' '=' GE_OP LE_OP EQ_OP NE_OP
%left  '+'  '-'
%left  '*'  '/' '%'
%left  '|'
%left  '&'

%union {
        char *str;              /* Ptr to constant string (strings are malloc'd) */
    };

%type <str> IDENTIFIER VOID CHAR SHORT INT FLOAT DOUBLE LONG SIGNED UNSIGNED STRING_CONSTANT CHAR_CONSTANT INT_CONSTANT FLOAT_CONSTANT
%token IDENTIFIER STRING_CONSTANT CHAR_CONSTANT INT_CONSTANT FLOAT_CONSTANT SIZEOF
%token INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME DEF
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOID
%token IF ELSE WHILE CONTINUE BREAK RETURN
%token EndOfFile

%nonassoc UNARY
%glr-parser

%%

stmt: start_state EndOfFile     {printf("Parsing successful\n"); showSymbolTable(); showConstantTable(); exit(0);}

start_state
	: global_declaration
	| start_state global_declaration
	;

global_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers direct_declarator compound_statement 
	| direct_declarator compound_statement
	;

declaration
	: declaration_specifiers init_declarator_list ';' 
	| error
	;

declaration_specifiers
	: type_specifier	
	| type_specifier declaration_specifiers	{ /*strcpy(temp, $1); strcat(temp, " "); strcat(temp, type); strcpy(type, temp);*/ }
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: direct_declarator
	| direct_declarator '=' init
	;

init
	: assignment_expression
	| '{' init_list '}'
	| '{' init_list ',' '}'
	;

init_list
	: init
	| init_list ',' init
	;

direct_declarator
	: IDENTIFIER			{ symbolInsert($1, type); }
	| '(' direct_declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	| '{' declaration_list statement_list declaration_list statement_list '}'
	| '{' declaration_list statement_list declaration_list '}'
	| '{' statement_list declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

statement
	: compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement %prec NO_ELSE
	| IF '(' expression ')' statement ELSE statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	;

jump_statement
	: CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

unary_expression
	: secondary_exp
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator typecast_exp
	;

secondary_exp
	: fundamental_exp
	| secondary_exp '[' expression ']'
	| secondary_exp '(' ')'
	| secondary_exp '(' arg_list ')'
	| secondary_exp '.' IDENTIFIER
	| secondary_exp INC_OP
	| secondary_exp DEC_OP
	;

arg_list
	: assignment_expression
	| arg_list ',' assignment_expression
	;

fundamental_exp
	: IDENTIFIER
	| STRING_CONSTANT		{ constantInsert($1, "string"); }
	| CHAR_CONSTANT     { constantInsert($1, "char"); }
	| FLOAT_CONSTANT	  { constantInsert($1, "float"); }
	| INT_CONSTANT			{ constantInsert($1, "int"); }
	| '(' expression ')'
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

logical_and_expression
	: unary_or_expression
	| logical_and_expression AND_OP unary_or_expression
	;

unary_or_expression
	: exor_expression
	| unary_or_expression '|' exor_expression
	;

exor_expression
	: and_expression
	| exor_expression '^' and_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

relational_expression
	: shift_exp
	| relational_expression '<' shift_exp
	| relational_expression '>' shift_exp
	| relational_expression LE_OP shift_exp
	| relational_expression GE_OP shift_exp
	;

shift_exp
	: addsub_exp
	| shift_exp LEFT_OP addsub_exp
	| shift_exp RIGHT_OP addsub_exp
	;

addsub_exp
	: multdivmod_exp
	| addsub_exp '+' multdivmod_exp
	| addsub_exp '-' multdivmod_exp
	;

multdivmod_exp
	: typecast_exp
	| multdivmod_exp '*' typecast_exp
	| multdivmod_exp '/' typecast_exp
	| multdivmod_exp '%' typecast_exp
	;

typecast_exp
	: unary_expression
	| '(' type_name ')' typecast_exp
	;

type_name
	: type_specifier_list
	| type_specifier_list direct_abstract_declarator
	;

type_specifier_list
	: type_specifier type_specifier_list    
	| type_specifier    
	;

type_specifier
	: VOID			{ strcpy(type, $1); }
	| CHAR			{ strcpy(type, $1); }
	| SHORT			{ strcpy(type, $1); }
	| INT			{ strcpy(type, $1); }
	| LONG			{ strcpy(type, $1); }
	| SIGNED		{ strcpy(type, $1); }
	| UNSIGNED	    { strcpy(type, $1); }
	;

direct_abstract_declarator
	: '(' direct_abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_list ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

constant_expression
	: conditional_expression
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers direct_declarator 
	| declaration_specifiers direct_abstract_declarator   
	| declaration_specifiers 
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

%%

extern char *yytext;
extern int yylineno;
extern FILE *yyin;

struct symbol
{
	char token[100];	// Name of the token
	char dataType[100];		// Date type: int, short int, long int, char etc
}symbolTable[100000], constantTable[100000];

int i=0; // Number of symbols in the symbol table
int c=0;

//Insert function for symbol table
void symbolInsert(char tokenName[], char DataType[])
{
    strcpy(symbolTable[i].token, tokenName);
    strcpy(symbolTable[i].dataType, DataType);
    i++;
}

void constantInsert(char tokenName[], char DataType[])
{
	for(int j=0; j<c; j++)
	{
		if(strcmp(constantTable[j].token, tokenName)==0)
			return;
	}
    strcpy(constantTable[c].dataType, DataType);
    strcpy(constantTable[c].token, tokenName);
    
    c++;
}

void showSymbolTable()
{

	printf("\n      Symbol Table         ");
	printf("\n----------------------------\nToken\t\tDatatype\n");
	printf("----------------------------\n");

  for(int j=0;j<i;j++)
    printf("%s\t\t %s \t\t\n",symbolTable[j].token,symbolTable[j].dataType);
	printf("----------------------------\n\n");
	
}

void showConstantTable()
{
	printf("\n      Constant Table      ");
	printf("\n----------------------------\nConstant\tDatatype\n");
	printf("----------------------------\n");

  for(int j=0;j<c;j++)
    printf("%s\t\t % s\t\t\n",constantTable[j].token,constantTable[j].dataType);
	printf("----------------------------\n");
	printf("\n");
	
}

int err=0;
int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	yyparse();
    
	if(err==0)
		printf("\nParsing complete\n");
	else
		printf("\nParsing failed\n");
	fclose(yyin);
	showSymbolTable();
	showConstantTable();
	return 0;
}

yyerror(char *s)
{
    printf("Parsing Error\n");
	err=1;
	printf("\nLine %d : %s\n", (yylineno), s);
	showSymbolTable();
	showConstantTable();
	exit(0);
}
