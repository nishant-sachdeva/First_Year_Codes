#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	for(int i =1 ; i<= n ; i += 2)
	{
		for(int j = (n-i)/2; j> 0 ; j--)
			printf(" ");
		int num = 0;
		for(int j = 1; j<= i ; j++)
		{
			num *= 10;
			num += j;
		}
		printf("%d\n", num);
	}
	for(int i = n-2; i >= 1 ; i -= 2)
	{
		for(int j = 1 ; j <= (n-i)/2 ; j++) printf(" ");
		int num = 0;
		for( int j =  1; j <= i ; j++)
		{
			num *= 10;
			num += j;
		}
		printf("%d\n", num);
	}
	return 0;
}

	
