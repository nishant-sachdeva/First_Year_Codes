#include<stdio.h>

int swap( int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	swap(&n,&m);
	printf("%d %d\n", n,m);
	scanf("%c%c", &n, &m);
	printf("%c %c\n",n, m);
	swap( &n, &m);
	printf("%c %c\n",n , m);
	return 0;
}
