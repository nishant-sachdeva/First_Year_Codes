#include<stdio.h>

int power(int a, int b)
{
	int ans = 1;
	for(int i = 0; i<b ; i++)
		ans *= a;
	return ans;
}

int main()
{
	int n;
	scanf("%d", &n);
	char arr[100];
	scanf("%s", arr);
	for(int i = 0 ; i<power(2,n) ; i++)
	{
		for(int j = 0 ; j<n ; j++)
		{
			if( i & (1<<j))
				printf("%c", arr[j]);
		}
		printf("\n");
	}
	return 0;
}
