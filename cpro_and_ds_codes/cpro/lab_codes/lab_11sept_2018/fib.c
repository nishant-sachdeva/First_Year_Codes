#include<stdio.h>

int main(void)
{
	int n ,  a =0, b = 1;
	scanf("%d", &n);
	for(int i = 0; i< n ; i++)
	{
		a = a+b;
		a = a+b; 
		b = a-b;
		a = a-b; 
	}
	printf("%d\n",a);
	return 0;
}
