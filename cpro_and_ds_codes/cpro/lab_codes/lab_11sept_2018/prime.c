#include<stdio.h>

int arr[1000005];
int main(void)
{
	for(int i = 0 ; i<= 100000 ; i++) arr[i] = 0;
	int a,b; scanf("%d%d", &a,&b);
	// now we create the sieve
	for(int i = 2 ; i<= 100 ; i++)
    {
		if(arr[i] == 1) continue;
		else
		{
			for(int j = 2 ; j<100 ; j++)
			{
				arr[i*j] = 1;
			}
		}
	}
	for(int i = a ; i<=b  ; i++) 
		if(arr[i] == 0) 
			printf("%d\n", i);
	return 0;
}
