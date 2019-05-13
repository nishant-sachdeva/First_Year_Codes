#include<stdio.h>

int main()
{
	int num; scanf("%d", &num);
	for(int n = 0 ; n < num ; n++)
	{
		for(int k = num - n  -1; k > 0 ; k--) printf(" ");
		int ans = 1;
		for( int i = 0 ; i<= n ; i++)
		{
			if(i == 0 || i == n) printf("1 ");
			else
			{
				ans = ans * (n-i + 1);
			        ans /= (i); 
			
			printf("%d ", ans);}
		}
		printf("\n");
	}
	return 0;
}

