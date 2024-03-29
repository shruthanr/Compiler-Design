%{
	#include <stdio.h>
	#include <stdlib.h>

	struct symbol_table_structure
	{
		int sno;
		char token[100];
		int type[100];
		int tn;
		int addr;
		float fvalue;
		int scope;
		int arrFlag;
		int funcFlag;
		int fType[100]; 
		int numParams; 
	}Symbol_Table[100];

	int var_addr = 0;
	int scope_incrementer=1;
	int j=8;
	int scope_stack[100];
	int index1=0;
	int end[100];
	int return_types[10];
	int gl1,gl2,curr_type=0,c=0,b;
	int type=258;
	int fname[100];
	int nP;
	int fTypes[100];
	int fTypes2[100];
	int temptype;
	int it;
	int temp;

	int n=0, return_types[10];

	void storereturn( int curr_type, int returntype )
	{
		return_types[curr_type] = returntype;
		return;
	}

	void insertscope(char *a,int s)
	{
		int i;
		for (i=0;i<n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token))
			{
				Symbol_Table[i].scope=s;
				break;
			}
		}
	}

	int returntype_func(int ct)
	{
		return return_types[ct-1];
	}

	int isArray(char* a)
	{
		int i;
		for (i=0;i<=n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token))
			{
				if (Symbol_Table[i].arrFlag==1)
					return Symbol_Table[i].fvalue;
						else
							return 0;
			}
		}
		return 0;
	}

	int retNumParams(char* a)
	{
		int i;
		for (i=0;i<=n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token))
			{
				return Symbol_Table[i].numParams;
			}
		}
		return 0;
	}

	void getParams(char* a)
	{
		int i;
		for (i=0;i<=n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token))
			{
				for (int j=0; j<Symbol_Table[i].numParams; j++)
					fTypes[j] = Symbol_Table[i].fType[j]; 
			}
		}
		return 0;
	}
	int returnScope(char *a,int cs)
	{
		//printf("\nString is: %s", a);
		int i;
		int max = 0;
		for (i=0;i<=n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token))
			{
				if (Symbol_Table[i].scope>=max)
					max = Symbol_Table[i].scope;
			}
		}
		return max;
	}

	int lookup(char *a)
	{
		int i;
		for (i=0;i<n;i++)
		{
			if ( !strcmp( a, Symbol_Table[i].token) )
				return 0;
		}
		return 1;
	}

	int returntype(char *a,int scope_curr)
	{
		int i;
		for (i=0;i<=n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token) && Symbol_Table[i].scope==scope_curr)
				return Symbol_Table[i].type[0];
		}
	}

	void update_value(char *a,char *b,int sc)
	{
		int i,j,k;
		int max=0;
		for (i=0;i<=n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token)   && sc>=Symbol_Table[i].scope)
			{
				if (Symbol_Table[i].scope>=max)
					max=Symbol_Table[i].scope;
			}
		}
		for (i=0;i<=n;i++)
		{
			if (!strcmp(a,Symbol_Table[i].token)   && max==Symbol_Table[i].scope)
			{
				float temp=atof(b);
				for (k=0;k<Symbol_Table[i].tn;k++)
				{
					if (Symbol_Table[i].type[k]==258||Symbol_Table[i].type[0]==269)
						Symbol_Table[i].fvalue=(int)temp;
					else
						Symbol_Table[i].fvalue=temp;
				}
			}
		}
	}

	void insert(char *name, int type, int addr, int arrFlag, int funcStatus)
	{
		int i;
		if (lookup(name))
		{
			strcpy(Symbol_Table[n].token,name);
			if (funcStatus == 1)
				Symbol_Table[n].funcFlag=1;
			Symbol_Table[n].tn=1;
			Symbol_Table[n].type[Symbol_Table[n].tn-1]=type;
			Symbol_Table[n].addr=addr;
			Symbol_Table[n].sno=n+1;
			Symbol_Table[n].arrFlag = arrFlag;
			n++;
		}
		else
		{
			if (funcStatus == 1)
				Symbol_Table[n].funcFlag=1;
			for (i=0;i<n;i++)
			{
				if (!strcmp(name,Symbol_Table[i].token))
				{
					Symbol_Table[i].tn++;
					Symbol_Table[i].type[Symbol_Table[i].tn-1]=type;
					break;
				}
			}
		}

		return;
	}
	void insertFunc(char *name, int type, int addr, int arrFlag, int params[100], int numParams)
	{
		int i;
		if (lookup(name))
		{
			strcpy(Symbol_Table[n].token,name);
			Symbol_Table[n].tn=1;
			Symbol_Table[n].type[Symbol_Table[n].tn-1]=type;
			Symbol_Table[n].addr=addr;
			Symbol_Table[n].sno=n+1;
			Symbol_Table[n].arrFlag = arrFlag;
			Symbol_Table[n].funcFlag = 1;
			for (int j=0; j<numParams; j++)
				Symbol_Table[n].fType[j] = params[j];
			Symbol_Table[n].numParams = numParams;
			n++;
		}
		else
		{
			for (i=0;i<n;i++)
			{
				if (!strcmp(name,Symbol_Table[i].token))
				{
					Symbol_Table[i].tn++;
					Symbol_Table[i].type[Symbol_Table[i].tn-1]=type;
					break;
				}
			}
		}

		return;
	}
	void insert_dup(char *name, int type, int addr,int s_c, int arrFlag)
	{
		strcpy(Symbol_Table[n].token,name);
		Symbol_Table[n].tn=1;
		Symbol_Table[n].type[Symbol_Table[n].tn-1]=type;
		Symbol_Table[n].addr=addr;
		Symbol_Table[n].sno=n+1;
		Symbol_Table[n].scope=s_c;
		Symbol_Table[n].arrFlag=arrFlag;
		n++;
		return;
	}

	void print()
	{
		int i,j;
		printf("\n------------------------------------------------------------------------------------------");
		printf("\n\t\t\t\t\tSYMBOL TABLE\n");
		printf("------------------------------------------------------------------------------------------");
		printf("\nToken\tValue\tScope\tisArray\tArrayDim\tType\tReturn Type\tArguments\n");
		for (i=0;i<n;i++)
		{
			if (Symbol_Table[i].type[0]==258 || Symbol_Table[i].type[0]==261|| Symbol_Table[i].type[0]==262|| Symbol_Table[i].type[0]==263)
				printf("%s\t%d\t%d\tFalse\t-\t",Symbol_Table[i].token,(int)Symbol_Table[i].fvalue,Symbol_Table[i].scope);
			else
			{
				if (Symbol_Table[i].arrFlag)
					printf("%s\t-\t%d\tTrue\t%d\t",Symbol_Table[i].token,Symbol_Table[i].scope, (int)Symbol_Table[i].fvalue);
				else if (Symbol_Table[i].type[0]==274)
					printf("%s\t-\t%d\tFalse\t-\t",Symbol_Table[i].token,Symbol_Table[i].scope);
				else
					printf("%s\t%.1f\t%d\tFalse\t-\t",Symbol_Table[i].token,Symbol_Table[i].fvalue,Symbol_Table[i].scope);
			}
			

			for (j=0;j<Symbol_Table[i].tn;j++)
			{
				if (Symbol_Table[i].type[j]==258)
					printf("\tINT");
				else if (Symbol_Table[i].type[j]==259)
					printf("\tFLOAT");
				else if (Symbol_Table[i].type[j]==274)
					printf("\tFUNCTION");
				else if (Symbol_Table[i].type[j]==269)
					printf("\tARRAY");
				else if (Symbol_Table[i].type[j]==260)
					printf("\tVOID");
				else if (Symbol_Table[i].type[j]==261)
			  		printf("\tUNSIGNED INT");
				else if (Symbol_Table[i].type[j]==263)
			    		printf("\tLONG INT");
				else if (Symbol_Table[i].type[j]==262)
			      		printf("\tSHORT INT");
			}
			printf("\t");
			for (int j=0;j<Symbol_Table[i].numParams;j++)
			{
				if (Symbol_Table[i].fType[j]==258)
					printf("INT,");
				else if (Symbol_Table[i].fType[j]==259)
					printf("FLOAT,");
				else if (Symbol_Table[i].fType[j]==274)
					printf("FUNCTION,");
				else if (Symbol_Table[i].fType[j]==269)
					printf("ARRAY,");
				else if (Symbol_Table[i].fType[j]==260)
					printf("VOID,");
				else if (Symbol_Table[i].fType[j]==261)
			  		printf("UNSIGNED INT,");
				else if (Symbol_Table[i].fType[j]==263)
			    		printf("LONG INT,");
				else if (Symbol_Table[i].fType[j]==262)
			      		printf("SHORT INT,");
			}
			printf("\n");
		}
		return;
	}
%}

%token<ival> INT FLOAT VOID UNSIGNED_INT S_INT L_INT
%token<str> ID INT_CONST FLOAT_CONST
%token WHILE FOR IF RETURN PREPROC STRING PRINT FUNCTION ARRAY ELSE
%token INCR DECR
%token EQUAL LE LT GE GT
%token MOD

%left '=' ','
%left '+' '-'
%left '*' '/'
%left INCR DECR
%left LE LT GE GT EQUAL
%left IF ELSE

%type<str> secondary_assignment consttype assignment_exp
%type<ival> Type

%union {
		int ival;
		char *str;
	}

%%

start : Function start
	| PREPROC start
	| Declaration start
	|
	;

Function
	: Type ID '(' ')' compound_stmt {
	 
	if ($1!=returntype_func(curr_type))
	{
		printf("\nError : Type mismatch : Line %d\n",printline());
	}

	if (!(strcmp($2,"printf") && strcmp($2,"scanf") && strcmp($2,"getc") && strcmp($2,"gets") && strcmp($2,"getchar") && strcmp	($2,"puts") && strcmp($2,"putchar") && strcmp($2,"clearerr") && strcmp($2,"getw") && strcmp($2,"putw") && strcmp($2,"putc") && strcmp($2,"rewind") && strcmp($2,"sprint") && strcmp($2,"sscanf") && strcmp($2,"remove") && strcmp($2,"fflush")))
		printf("Error : Type mismatch in redeclaration of %s : Line %d\n",$2,printline());
	else
	{
		insert($2,FUNCTION,var_addr, 0, 1);
		insert($2,$1,var_addr, 0, 0);
		var_addr+=4;
	}
	}
	| Type ID '(' param_list ')' compound_stmt {
	

	if ($1!=returntype_func(curr_type))
	{
		printf("\nError : Type mismatch : Line %d\n",printline());
	}

	if (!(strcmp($2,"printf") && strcmp($2,"scanf") && strcmp($2,"getc") && strcmp($2,"gets") && strcmp($2,"getchar") && strcmp	($2,"puts") && strcmp($2,"putchar") && strcmp($2,"clearerr") && strcmp($2,"getw") && strcmp($2,"putw") && strcmp($2,"putc") && strcmp($2,"rewind") && strcmp($2,"sprint") && strcmp($2,"sscanf") && strcmp($2,"remove") && strcmp($2,"fflush")))
		printf("Error : Type mismatch in redeclaration of %s : Line %d\n",$2,printline());
	else
	{
		insertFunc($2,FUNCTION,var_addr, 0, fname, nP);
		insert($2,$1,var_addr, 0, 0);
		var_addr+=4;
	}
	};

param_list: Type ID { nP = 1; fname[nP-1] = $1; }
	| param_list ',' Type ID { nP++; fname[nP-1] = $3; }; 

Type
	: INT
	| FLOAT
	| VOID
  | UNSIGNED_INT
  | S_INT
  | L_INT
	;

compound_stmt
	: '{' statement_list '}'
	;

statement_list
	: statement_list stmt
	| compound_stmt
	|
	;

stmt
	: Declaration
	| if_stmt
	| while_stmt
	| for_stmt
	| function_call
	| RETURN consttype ';' {
					if (!(strspn($2,"0123456789")==strlen($2)))
						storereturn(curr_type,FLOAT);
					else
						storereturn(curr_type,INT); curr_type++;
				}
	| RETURN ';' {storereturn(curr_type,VOID); curr_type++;}
	| ';'
	| PRINT '(' STRING ',' exp ')' ';'
	| PRINT '(' STRING ')' ';'
	| compound_stmt
	;

function_call: ID '(' call_list ')' ';' {
	if (lookup($1))
		printf("\nError: Undeclared function %s : Line %d\n", $1, printline());
	else
	{
		if (retNumParams($1) == 0)
			printf("\nError : Parameter list does not match signature : Line %d\n", printline()); 
		getParams($1);				
	}

	for (int j=0; j<retNumParams($1); j++)
	{
		if (fTypes[j] != fTypes2[j])
			printf("\nError : Parameter list does not match signature : Line %d\n", printline());
	}
	
}  
| ID '(' ')' ';' {
	if (lookup($1))
		printf("\nError: Undeclared function %s : Line %d\n", $1, printline());
	else
	{
		if (retNumParams($1) != 0)
			printf("\nError : Parameter list does not match signature : Line %d\n", printline()); 
	}
};

call_list : ID { temptype = returntype($1, scope_stack[index1-1]); it = 0; fTypes2[it] = temptype; }
	| consttype { temptype = temp; it = 0; fTypes2[it] = temptype; }
	| call_list ',' ID { it++; temptype = returntype($3, scope_stack[index1-1]); fTypes2[it] = temptype;}
	| call_list ',' consttype { temptype = temp; it++; fTypes2[it] = temptype;}
	;

if_stmt
	: IF '(' expr1 ')' compound_stmt
	| IF '(' expr1 ')' compound_stmt ELSE compound_stmt
	;

while_stmt
	: WHILE '(' expr1 ')' compound_stmt
	;

for_stmt
	: FOR '(' expr1 ';' expr1 ';' expr1 ')' compound_stmt

expr1
	: expr1 LE expr1
	| expr1 LT expr1
	| expr1 GE expr1
	| expr1 GT expr1
	| expr1 EQUAL expr1
	| secondary_assignment
	|
	;

secondary_assignment : ID '=' secondary_assignment
	{
	  c=0;
		int scope_curr=returnScope($1,scope_stack[index1-1]);
		int type=returntype($1,scope_curr);
		if ((!(strspn($3,"0123456789")==strlen($3))) && type==258)
			printf("\nError : Type Mismatch : Line %d\n",printline());
		if (!lookup($1))
		{
			int curr_scope=scope_stack[index1-1];
			int scope=returnScope($1,curr_scope);
			if ((scope<=curr_scope && end[scope]==0) && !(scope==0))
				update_value($1,$3,curr_scope);
		}
		if (isArray($1))
				printf("\nError: array Identfier has no subscript: Line %d\n", printline());

		}

	| ID ',' secondary_assignment    {
					if (lookup($1))
						printf("\nUndeclared Variable %s : Line %d\n",$1,printline());

						if (isArray($1))
								printf("\nError: array identfier has no subscript: Line %d\n", printline());

				}
	| assignment_exp
	| consttype ',' secondary_assignment
	| ID  {
		if (lookup($1))
			printf("\nUndeclared Variable %s : Line %d\n",$1,printline());

			if (isArray($1))
				printf("\nError: Non-array variable used as an array: Line %d\n", printline());

		}
	| exp
	| consttype
	;

assignment_exp :  ID '[' INT_CONST ']' '=' exp {
			if (lookup($1))
				printf("\nUndeclared Variable %s : Line %d\n",$1,printline());

			if (isArray($1)==0)
				printf("\nError: Non-array variable used as an array: Line %d\n", printline());

				float bound = isArray($1);

				if (isArray($1) && (atoi($3) >= bound || atoi($3) < 0))
					printf("\nError: array subscript out of bounds : Line %d\n", printline());

		}
		;

exp : ID {
	if (isArray($1))
	 printf("\nError: array identifier has no subscript: Line %d\n", printline());

	if (c==0)
	{
		c=1;
		int scope_curr=returnScope($1,scope_stack[index1-1]);
		b=returntype($1,scope_curr);
	}
	else
	{
		int scope_curr1=returnScope($1,scope_stack[index1-1]);
		if (b!=returntype($1,scope_curr1))
			printf("\nError : Type Mismatch : Line %d\n",printline());
	}
	if (!lookup($1))
	{
		int curr_scope=scope_stack[index1-1];
		int scope=returnScope($1,curr_scope);
		if (!(scope<=curr_scope && end[scope]==0))
			printf("\nError : Variable %s out of scope : Line %d\n",$1,printline());
	}
  else
    printf("\nError : Undeclared Variable %s : Line %d\n",$1,printline());
	}
	| ID '[' INT_CONST ']'{
		if (c==0)
		{
			c=1;
			int scope_curr=returnScope($1,scope_stack[index1-1]);
			b=returntype($1,scope_curr);
		}
		else
		{
			int scope_curr1=returnScope($1,scope_stack[index1-1]);
			if (b!=returntype($1,scope_curr1))
				printf("\nError : Type Mismatch : Line %d\n",printline());
		}
		if (!lookup($1))
		{
			int curr_scope=scope_stack[index1-1];
			int scope=returnScope($1,curr_scope);
			if (!(scope<=curr_scope && end[scope]==0))
				printf("\nError : Variable %s out of scope : Line %d\n",$1,printline());
		}
	  else
	    printf("\nError : Undeclared Variable %s : Line %d\n",$1,printline());

		if (isArray($1)==0)
			printf("\nError: Non-array variable used as an array: Line %d\n", printline());

		float bound = isArray($1);

		if (isArray($1) && (atoi($3) >= bound || atoi($3) < 0) )
			printf("\nError: array subscript out of bounds : Line %d\n", printline());

	}
	| exp '+' exp
	| exp '-' exp
	| exp '*' exp
	| exp '/' exp
	| exp MOD INT_CONST
	| '(' exp '+' exp ')'
	| '(' exp '-' exp ')'
	| '(' exp '*' exp ')'
	| '(' exp '/' exp ')'
	| consttype
	| '(' exp ')'
	| INCR exp
	| DECR exp
	| exp INCR
	| exp DECR
	;

consttype : INT_CONST { temp = 258;}
	| FLOAT_CONST { temp = 259;}
	;

Declaration
	: Type ID '=' consttype ';'
		{
			if ( (!(strspn($4,"0123456789")==strlen($4))) && $1==258)
				printf("\nError : Type Mismatch : Line %d\n",printline());

			if (!lookup($2))
			{
				int curr_scope=scope_stack[index1-1];
				int previous_scope=returnScope($2,curr_scope);
				if (curr_scope==previous_scope)
					printf("\nError : Redeclaration of %s : Line %d\n",$2,printline());
				else
				{
					insert_dup($2,$1,var_addr,curr_scope, 0);
					update_value($2,$4,scope_stack[index1-1]);
					var_addr+=4;
				}
			}
			else
			{
				int scope=scope_stack[index1-1];
				insert($2,$1,var_addr, 0, 0);
				insertscope($2,scope);
				update_value($2,$4,scope_stack[index1-1]);
				var_addr+=4;
			}
		}
	| Type ID ';' {
		if (!lookup($2))
		{
			int curr_scope=scope_stack[index1-1];
			int previous_scope=returnScope($2,curr_scope);
			if (curr_scope==previous_scope)
				printf("\nError : Redeclaration of %s : Line %d\n",$2,printline());
			else
			{
				insert_dup($2,$1,var_addr,curr_scope, 0);
				var_addr+=4;
			}
		}
		else
		{
			int scope=scope_stack[index1-1];
			insert($2,$1,var_addr, 0, 0);
			insertscope($2,scope);
			var_addr+=4;
		}
	}
	| secondary_assignment ';'  {
				if (!lookup($1))
				{
					int curr_scope=scope_stack[index1-1];
					int scope=returnScope($1,curr_scope);
					if (!(scope<=curr_scope && end[scope]==0))
						printf("\nError : Variable %s out of scope : Line %d\n",$1,printline());
				}
				else
					printf("\nError : Undeclared Variable %s : Line %d\n",$1,printline());
				}

	| Type ID '[' INT_CONST ']' ';' {
						insert($2,ARRAY,var_addr,1,0);
						insert($2,$1,var_addr,1,0);
						update_value($2,$4,scope_stack[index1-1]);
						int scope=scope_stack[index1-1];
						insertscope($2, scope);
						var_addr+=4;
						if (atoi($4)<=0)
						{
							printf("\nError: Illegal array subscript %d : Line %d\n", atoi($4), printline());
						}
					}
	| error
	;

%%

#include "lex.yy.c"
#include<ctype.h>
int main(int argc, char *argv[])
{
	yyin =fopen(argv[1],"r");
	if (!yyparse())
	{
		printf("PARSING DONE\n");
		print();
	}
	else
	{
		printf("Error\n");
	}
	fclose(yyin);
	return 0;
}

yyerror(char *s)
{
	printf("\nLine %d : %s %s\n",yylineno,s,yytext);
}

int printline()
{
	return yylineno;
}

void block_start()
{
	scope_stack[index1]=scope_incrementer;
	scope_incrementer++;
	index1++;
	return;
}

void block_end()
{
	index1--;
	end[scope_stack[index1]]=1;
	scope_stack[index1]=0;
	return;
}
