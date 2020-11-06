#include <stdio.h>

int main()
{
    int num = 20;
    int a;
    if(num < 20)
    {
        a = (num++) - (num * num);
    }
    else if(num > 20)
    {
        a = (num--) * (num / 20);
    }
    else
    {
        a = num / (num + (3*num));
    }

    printf("%d", a);
    
}