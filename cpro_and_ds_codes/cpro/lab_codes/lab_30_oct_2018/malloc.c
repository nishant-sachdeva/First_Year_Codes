#include<stdio.h>
#include<stdlib.h>


int main()
{
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc( sizeof(int)*n);
	for ( int i=0 ; i<n ; i++){
		scanf("%d", &a[i]);
	}
	for(int i =0; i<n ; i++){
		printf("%d \n", a[i]);
	}
	// now we will scan multiple strings
 	char **arr = (char **)malloc(sizeof(char*)*n);
	// this line makes an array of pointers
	
	for(int i =0 ; i<n ; i++)
	{
		int ni; scanf("%d", &ni);
		arr[i] = (char *)malloc( sizeof(char)*ni);
		for(int j =0; j<ni ; j++)
		{
			scanf(" %c", &arr[i][j]);
		}
	}
	printf("%d\n", sizeof(char*));
	return 0;
}
