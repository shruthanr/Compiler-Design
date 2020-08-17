#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <limits.h>

char bstack[100];

struct hashtable{
    char name[100];
    char type[100];
    int len;
} table[1000];

int Hash(char *s){
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

void insert_symbol(char *lexeme, char *token_name){
    
    int l1 = strlen(lexeme);
    int l2 = strlen(token_name);
    int v = Hash(lexeme);
    if(table[v].len == 0){
        strcpy(table[v].name, lexeme);
        strcpy(table[v].type, token_name);
        
        table[v].len = strlen(lexeme);
        return;
    }

    if(strcmp(table[v].name,lexeme) == 0)
    return;

    int i, pos = 0;

    for (i = 0; i < 1001; i++){
        if(table[i].len == 0){
            pos = i;
            break;
        }
    }

    strcpy(table[pos].name, lexeme);
    strcpy(table[pos].type, token_name);
    table[pos].len = strlen(lexeme);

}

void print(){
    int i;
    for(i = 0;i < 1001; i++){
        if(table[i].len == 0){
            continue;
        }
        printf("%15s \t %40s\n",table[i].name,table[i].type);
    }
}


extern FILE* yyin;
int main(){

    int i;
    for (i = 0; i < 1001; i++){
        table[i].len=0;
    }
    yyin = fopen("test1.c","r");

    yylex();
    printf("\n\n----------------------------------------------------------------------------\n\t\t\t\tSYMBOL TABLE\n----------------------------------------------------------------------------\n");   
	printf("\tLexeme \t\t\t\t\t\tToken\n"); 
	printf("----------------------------------------------------------------------------\n");
    print();
}