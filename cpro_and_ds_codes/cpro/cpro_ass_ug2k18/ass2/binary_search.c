#include <stdio.h>

int arr[1000];

int lower_bound(int arr[], int key , int left, int right)
{
	int mid;
	while( left < right)
	{
		mid  = ( left + right)/2;
		if( val <= mid)
			right =mid;
		else
			left = mid + 1;
	}
	return left;
}

int upper_bound(int arr[], int key, int left, int right)
{
	int mid;
	while( left < right )
	{
		mid = (left + right)/2;
		if(key < arr[mid])
			right = mid;
		else 
			left = mid +1;	
	}
	return left;
}


int main()
{
	int n, q;
	scanf("%d %d" , &n, &q);
	for(int i =1 ; i<=n ; i++)
	{
		scanf("%d", &arr[i]);
	}
	for(int i =1 ; i<=q ;i++)
	{
		int num;
		scanf("%d", &num);
		int lower = bs_lower(num , 1 , n);
		int upper = bs_upper(num, 1, n);
		printf("lower bound is %d and upper bound is %d\n",lower , upper );
	}
}