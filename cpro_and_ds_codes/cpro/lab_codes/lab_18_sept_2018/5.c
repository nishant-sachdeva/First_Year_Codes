#include<stdio.h>

int main()
{
	int n; scanf("%d", &n); int num = 1;
	for(int i=1; i<=n; i++)
	{
		for(int space = 0 ; space < 2*(i-1); space ++)
		{
			printf("-");
		}	
		int arr[50];
		int k =0;
		for(int j =1 ;j <= n - i +1; j++)
		{
			arr[k] = num;
			k++; num++;
		}
		arr[k] = (n+1)*(n+1) - n -arr[k-1];
		k++;
		for( int j = n + -i + 1 ; j >1 ; j--)
		{
			arr[k] = arr[k-1] + 1;
			k++;
		}
		for(int j = 0 ; j<k-1 ; j++) printf("%d*", arr[j]);
		printf("%d\n" , arr[k-1]);
	}
	return 0;
}
