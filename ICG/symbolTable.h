// int checkscope(char*);
// int check_id_is_func(char *);
// void insertST(char*, char*);
// void insertSTnest(char*, int);
// void insertSTparamscount(char*, int);
// int getSTparamscount(char*);
// int check_duplicate(char*);
// int check_declaration(char*, char *);
// int check_params(char*);
// int duplicate(char *s);
// int checkarray(char*);
// void insertSTF(char*);
// char gettype(char*,int);
// char getfirst(char*);



struct symboltable
{
    char name[100];
    char class[100];
    char type[100];
    char value[100];
    int nestval;
    int lineno;
    int length;
    int params_count;
    int scope;
}ST[1001];

struct constanttable
{
    char name[100];
    char type[100];
    int length;
}CT[1001];

int scope_stack[100] = {0};
int scope_index = 1;
int scope_val = 1;
int currnest = 0;
extern int yylval;

void scope_start()
{
    scope_stack[scope_index] = scope_val;
    scope_val++;
    scope_index++;
}

void scope_end()
{
    scope_index--;
    scope_stack[scope_index] = 0;
}

int hash(char *str)
{
    int value = 0;
    for(int i = 0 ; i < strlen(str) ; i++)
    {
        value = 10*value + (str[i] - 'A');
        value = value % 1001;
        while(value < 0)
            value = value + 1001;
    }
    return value;
}

int lookupST(char *str)
{
    int value = hash(str);
    if(ST[value].length == 0)
    {
        return 0;
    }
    else if(strcmp(ST[value].name,str)==0)
    {
        
        return value;
    }
    else
    {
        for(int i = value + 1 ; i!=value ; i = (i+1)%1001)
        {
            if(strcmp(ST[i].name,str)==0)
            {
                
                return i;
            }
        }
        return 0;
    }
}

int lookupCT(char *str)
{
    int value = hash(str);
    if(CT[value].length == 0)
        return 0;
    else if(strcmp(CT[value].name,str)==0)
        return 1;
    else
    {
        for(int i = value + 1 ; i!=value ; i = (i+1)%1001)
        {
            if(strcmp(CT[i].name,str)==0)
            {
                return 1;
            }
        }
        return 0;
    }
}

void insertSTline(char *str1, int line)
{
    for(int i = 0 ; i < 1001 ; i++)
    {
        if(strcmp(ST[i].name,str1)==0)
        {
            ST[i].lineno = line;
        }
    }
}


void insertST(char *str1, char *str2)
{
    if(lookupST(str1))
    {
        if(strcmp(ST[lookupST(str1)].class,"Identifier")==0 && strcmp(str2,"Array Identifier")==0)
        {
            printf("Error use of array\n");
            exit(0);
        }	
        return;
    }
    else
    {
        int value = hash(str1);
        if(ST[value].length == 0)
        {
            strcpy(ST[value].name,str1);
            strcpy(ST[value].class,str2);
            ST[value].length = strlen(str1);
            ST[value].nestval = 9999;
            ST[value].params_count = -1;
            ST[value].scope = scope_stack[scope_index - 1];
            insertSTline(str1,yylineno);
            return;
        }

        int pos = 0;

        for (int i = value + 1 ; i!=value ; i = (i+1)%1001)
        {
            if(ST[i].length == 0)
            {
                pos = i;
                break;
            }
        }

        strcpy(ST[pos].name,str1);
        strcpy(ST[pos].class,str2);
        ST[pos].length = strlen(str1);
        ST[pos].nestval = 9999;
        ST[pos].params_count = -1;
        ST[pos].scope = scope_stack[scope_index - 1];
        insertSTline(str1,yylineno);
    }
}

void insertSTtype(char *str1, char *str2)
{
    for(int i = 0 ; i < 1001 ; i++)
    {
        if(strcmp(ST[i].name,str1)==0)
        {
            strcpy(ST[i].type,str2);
        }
    }
}

void insertSTvalue(char *str1, char *str2)
{
    for(int i = 0 ; i < 1001 ; i++)
    {
        if(strcmp(ST[i].name,str1)==0 && ST[i].nestval == currnest)
        {
            strcpy(ST[i].value,str2);
        }
    }
}


void insertSTnest(char *s, int nest)
{
    if(lookupST(s) && ST[lookupST(s)].nestval != 9999)
    {
            int pos = 0;
            int value = hash(s);
        for (int i = value + 1 ; i!=value ; i = (i+1)%1001)
        {
            if(ST[i].length == 0)
            {
                pos = i;
                break;
            }
        }

        strcpy(ST[pos].name,s);
        strcpy(ST[pos].class,"Identifier");
        ST[pos].length = strlen(s);
        ST[pos].nestval = nest;
        ST[pos].params_count = -1;
        ST[pos].lineno = yylineno;
        ST[pos].scope = scope_stack[scope_index - 1];
    }
    else
    {
        for(int i = 0 ; i < 1001 ; i++)
        {
            if(strcmp(ST[i].name,s)==0 )
            {
                ST[i].nestval = nest;
            }
        }
    }
}

void insertSTparamscount(char *s, int count1)
{

    for(int i = 0 ; i < 1001 ; i++)
    {
        if(strcmp(ST[i].name,s)==0 )
        {
            ST[i].params_count = count1;
        }
    }
}

int getSTparamscount(char *s)
{
    for(int i = 0 ; i < 1001 ; i++)
    {
        if(strcmp(ST[i].name,s)==0 )
        {
            return ST[i].params_count;
        }
    }
    return -1;
}

void insertSTF(char *s)
{
    for(int i = 0 ; i < 1001 ; i++)
    {
        if(strcmp(ST[i].name,s)==0 )
        {
            strcpy(ST[i].class,"Function");
            return;
        }
    }

}

void insertCT(char *str1, char *str2)
{
    if(lookupCT(str1))
        return;
    else
    {
        int value = hash(str1);
        if(CT[value].length == 0)
        {
            strcpy(CT[value].name,str1);
            strcpy(CT[value].type,str2);
            CT[value].length = strlen(str1);
            return;
        }

        int pos = 0;

        for (int i = value + 1 ; i!=value ; i = (i+1)%1001)
        {
            if(CT[i].length == 0)
            {
                pos = i;
                break;
            }
        }

        strcpy(CT[pos].name,str1);
        strcpy(CT[pos].type,str2);
        CT[pos].length = strlen(str1);
    }
}

void deletedata (int nesting)
{
    for(int i = 0 ; i < 1001 ; i++)
    {
        if(ST[i].nestval == nesting)
        {
            ST[i].nestval = 99999;
        }
    }


}

int checkscope(char *s)
{
    int flag = 0;
    for(int i = 0 ; i < 1000 ; i++)
    {
        if(strcmp(ST[i].name,s)==0)
        {
            if(ST[i].nestval > currnest)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
    }
    if(!flag)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_id_is_func(char *s)
{
    for(int i = 0 ; i < 1000 ; i++)
    {
        if(strcmp(ST[i].name,s)==0)
        {
            if(strcmp(ST[i].class,"Function")==0)
                return 1;
        }
    }
    return 0;
}

int checkarray(char *s)
{
    for(int i = 0 ; i < 1000 ; i++)
    {
        if(strcmp(ST[i].name,s)==0)
        {
            if(strcmp(ST[i].class,"Array Identifier")==0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int duplicate(char *s)
{
    for(int i = 0 ; i < 1000 ; i++)
    {
        if(strcmp(ST[i].name,s)==0)
        {				
            if(ST[i].nestval == currnest)
            {
                return 1;
            }
        }
    }
    
    return 0;
}

int check_duplicate(char* str)
{
    for(int i=0; i<1001; i++)
    {
        if(strcmp(ST[i].name, str) == 0 && strcmp(ST[i].class, "Function") == 0)
        {
            printf("Function redeclaration not allowed\n");
            exit(0);
        }
    }
}

int check_declaration(char* str, char *check_type)
{
    for(int i=0; i<1001; i++)
    {
        if(strcmp(ST[i].name, str) == 0 && strcmp(ST[i].class, "Function") == 0 || strcmp(ST[i].name,"printf")==0 )
        {
            return 1;
        }
    }
    return 0;
}

int check_params(char* type_specifier)
{
    if(!strcmp(type_specifier, "void"))
    {
        printf("Parameters cannot be of type void\n");
        exit(0);
    }
    return 0;
}

char gettype(char *s, int flag)
{
        for(int i = 0 ; i < 1001 ; i++ )
        {
            if(strcmp(ST[i].name,s)==0)
            {
                return ST[i].type[0];
            }
        }
    
}

void printST()
{
    printf("%10s | %15s | %10s | %10s | %10s | %15s | %10s |\n","SYMBOL", "CLASS", "TYPE","VALUE", "LINE NO", "SCOPE", "PARAMS COUNT");
    for(int i=0;i<100;i++) {
        printf("-");
    }
    printf("\n");
    for(int i = 0 ; i < 1001 ; i++)
    {
        if(ST[i].length == 0 || strcmp(ST[i].class, "Keyword") == 0 || strcmp(ST[i].name, "printf") == 0)
        {
            continue;
        }
        printf("%10s | %15s | %10s | %10s | %10d | %15d | %10d |\n",ST[i].name, ST[i].class, ST[i].type, ST[i].value, ST[i].lineno, ST[i].scope, ST[i].params_count);
    }
}


void printCT()
{
    printf("%10s | %15s\n","NAME", "TYPE");
    for(int i=0;i<81;i++) {
        printf("-");
    }
    printf("\n");
    for(int i = 0 ; i < 1001 ; i++)
    {
        if(CT[i].length == 0)
            continue;

        printf("%10s | %15s\n",CT[i].name, CT[i].type);
    }
}
