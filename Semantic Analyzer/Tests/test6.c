// Redeclaration of variable in the same scope

#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;
    printf("%d, %d", a, b);
    int a = 40;
    printf("%d, %d", a, b);
}