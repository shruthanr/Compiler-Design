// Variable out of scope

#include <stdio.h>

int main()
{
    {
        int a = 10;
        int b = 20;
        printf("a is %d\n", a);
        printf("b is %d\n", b);
    }
    a = 40;

    return 0;
}