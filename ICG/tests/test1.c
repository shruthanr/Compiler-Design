#include <stdio.h>

int global_var;

int sample_function()
{
	int a = 10;
	int b = 20;
	int c = (a * b) + (a / b) * b;
	int arr[10];
	arr[0] = 1;
	return c;
}

void main()
{
	int a = 1;
	int b,i;

	while(a < 5)
	{
		int c;
		a = a+b;
		for(i=0;i<b;i++)
		{
			b++;
			c = sample_function();
		}
		a++;
	}
	
}