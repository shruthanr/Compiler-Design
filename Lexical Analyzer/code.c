#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <limits.h>

struct Table{
    char name[100];
    char type[100];
    int len;
} symbolTable[1001];

int hashFunction(char *s){
    int mod = 1001;
    int l = strlen(s), val = 0, i;
    for(i = 0; i < l; i++){
        val = val * 10 + (s[i]-'A');
        val = val % mod;
        while(val < 0){
            val += mod;
        }
    }
    return val;
}

void insertToken(char *token, char *tokenType){
    
    int l1 = strlen(token);
    int l2 = strlen(tokenType);
    int v = hashFunction(token);
    if(symbolTable[v].len == 0){
        strcpy(symbolTable[v].name, token);
        strcpy(symbolTable[v].type, tokenType);
        
        symbolTable[v].len = strlen(token);
        return;
    }

    if (strcmp(symbolTable[v].name,token) == 0)
        return;

    int i, pos = 0;

    for (i = 1; i < 1001; i++){
        int x = (i+v)%1001;
        if (strcmp(symbolTable[x].name,token) == 0)
            return;
        if(symbolTable[x].len == 0){

            pos = x;
            break;
        }
    }
   
    strcpy(symbolTable[pos].name, token);
    strcpy(symbolTable[pos].type, tokenType);
    symbolTable[pos].len = strlen(token);

}

void print(){
    int i;
    for(i = 0;i < 1001; i++){
        if(symbolTable[i].len == 0){
            continue;
        }
        printf("%15s \t %40s\n",symbolTable[i].name,symbolTable[i].type);
    }
}


extern FILE* yyin;
int main(){

    int i;
    for (i = 0; i < 1001; i++){
        strcpy(symbolTable[i].name, "");
        strcpy(symbolTable[i].type, "");
        symbolTable[i].len = 0;
    }
    yyin = fopen("test.c","r");

    yylex();
    printf("\n\n----------------------------------------------------------------------------\n\t\t\t\tSYMBOL TABLE\n----------------------------------------------------------------------------\n");   
	printf("\tToken \t\t\t\t\t\tToken Type\n"); 
	printf("----------------------------------------------------------------------------\n");
    print();
}

