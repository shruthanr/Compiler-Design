#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <limits.h>

struct Table{
    char name[100];
    char type[100];
    int len;
} symbolTable[1000];

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

void insertLexeme(char *lexeme, char *token_name){
    
    int l1 = strlen(lexeme);
    int l2 = strlen(token_name);
    int v = hashFunction(lexeme);
    if(symbolTable[v].len == 0){
        strcpy(symbolTable[v].name, lexeme);
        strcpy(symbolTable[v].type, token_name);
        
        symbolTable[v].len = strlen(lexeme);
        return;
    }

    if(strcmp(symbolTable[v].name,lexeme) == 0)
    return;

    int i, pos = 0;

    for (i = 0; i < 1001; i++){
        if(symbolTable[i].len == 0){
            pos = i;
            break;
        }
    }

    strcpy(symbolTable[pos].name, lexeme);
    strcpy(symbolTable[pos].type, token_name);
    symbolTable[pos].len = strlen(lexeme);

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
        symbolTable[i].len=0;
    }
    yyin = fopen("test.c","r");

    yylex();
    printf("\n\n----------------------------------------------------------------------------\n\t\t\t\tSYMBOL TABLE\n----------------------------------------------------------------------------\n");   
	printf("\tLexeme \t\t\t\t\t\tToken\n"); 
	printf("----------------------------------------------------------------------------\n");
    print();
}