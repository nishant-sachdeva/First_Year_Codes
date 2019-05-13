#include<stdio.h>
#include<stdlib.h>

int main(){
	int n; 
	int size[10];
	scanf("%d", &n);
	int ** arr = (int **)malloc(sizeof(int *)*n);
	for(int i = 0; i<n ; i++)
	{
		scanf("%d", &size[i]);
		arr[i] = (int *)malloc( sizeof(int*)*size[i]);
		for(int j=0; j<size[i] ; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	// here we have scanned the thing ;
	// now we will sort it
	for(int c =0 ;c<n-1 ; c++){
		for (int d = 0 ; d < n - c -1; d++)
		{
			if (size[d] > size[d+1]) /* For decreasing order use < */
			{
				int swap   = size[d];
				size[d]   = size[d+1];
				size[d+1] = swap;
				int *temp = arr[d];
				arr[d] = arr[d+1];
				arr[d+1] = temp;
			}
		}
	}
	for(int i =0 ; i<n ; i++)
	{
		for(int j =0  ; j<size[i]; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
