#include<stdio.h>

int main()
{
	int n, rotate; scanf("%d %d", &n , &rotate);
	int arr[n]; rotate %= n;
	for(int i =0 ; i<n; i++) 
	{
		scanf("%d" , &arr[( i + n - rotate)%n] );
	//	if( arr[i] >= max) { max = arr[i] ; max_index = i; } 
	}
	/*int rotate =0; scanf("%d", &rotate);
	 rotate %= n;
	// now final index of every elemwnt is i + size - rotate;
	
	for ( int i = 0 ; i<n ; i++)
	{
		arr[max_index] = arr[(i+size - rotate)%size];
		//arr[max_index] += arr[i + size - rotate];
		arr[(i + size - rotate)%size] = arr[i];
		arr[i] = max;

	}*/



	
	for(int i = 0; i<n; i++)
	{
		printf("%d ", arr[i]);
	} printf("\n");
	return 0;
}
