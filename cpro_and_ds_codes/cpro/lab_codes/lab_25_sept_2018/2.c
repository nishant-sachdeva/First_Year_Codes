#include<stdio.h>

int arr1[100005];

int main()
{
	int n; scanf("%d", &n); char arr[n]; int max =0;
		scanf("%s", arr);
	for(int i =0 ; i< n ; i++)
	{
		arr1[arr[i]] ++;
		if( arr[i] >= max) { max = arr[i]; }
	}
	for(int i =0 ; i<= max ; i++)
	{
		if ( arr1[i] >=1) printf("%c %d \n" , i, arr1[i]);
	}
	return 0;
}
