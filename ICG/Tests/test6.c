// Redeclaration of variable in the same scope

#include <stdio.h>

int main()
{
    int a = 10;
    printf("%d", a);
    int a = 40;
    printf("%d", a);

    return 0;
}