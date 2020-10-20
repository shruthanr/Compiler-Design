// Function call parameter list not matching function signature

#include <stdio.h>

void func(int a)
{
    int b = 10;
}

int main()
{
    func();
}