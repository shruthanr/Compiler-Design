//Program to check if given string is a palindrome

#include <stdio.h>

int main()
{
    float testvar;
    float temp;
    float rev = 0;
    testvar = 101;
    temp = 101;
    while (temp > 0)
    {
        float d;
        d = temp % 10;
        rev = rev*10 + d;
        temp = temp/10;
    }

    if(testvar == rev)
    {
        printf("palindrome\n");
    }
    else
    {
        printf("not a palindrome\n");
    }
    
    return 0;
}