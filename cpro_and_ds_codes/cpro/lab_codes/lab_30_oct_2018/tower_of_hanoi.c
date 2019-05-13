#include<stdio.h>

void tower( int n , int from ,  int to , int inter)
{
	if( n == 1)
	{
		printf("disk %d from %d to %d \n", n , from, to);
		return ;
	}
	tower( n -1, from , inter , to);
	printf("disk %d from %d to %d \n", n, from, to);
	tower( n-1, inter , to, from);
	return ;
}



int main()
{
	int n;
	scanf("%d", &n);
	tower(n , 1 , 3 , 2);
	return 0;
}
