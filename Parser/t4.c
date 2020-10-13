// Has no errors
#include<stdio.h>
#define x 30

int main(void) {
    int m, n;
    m = n = x;
    n = n*10;
    while(m < n) {
        printf("%d", m);
    }
    return 0;

}