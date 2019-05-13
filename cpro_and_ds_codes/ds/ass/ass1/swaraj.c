#include<stdio.h>
#include<stdlib.h>

#define ll long long int
#define get(n) int n; if(scanf("%d", &n))
#define gets(n) char n ; if(scanf("%c", &n))
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

int compare(const void *  a , const void * b)
{
	int num1 = *(const int *)a;
	int num2 = *(const int *)b;

	if(num1 < num2) return -1;
	else  if(num1 > num2) return 1;
	return 0;
}

int main()
{
	get(t);
	while(t--)
	{
		get(n);
		int arr[10000];
		for (int i = 0; i < n; ++i)
		{
			get(ni);
			arr[i] = ni;
		}
		get(k);
		qsort(arr, n, sizeof(int), compare);
		for (int i = 0; i < n; ++i)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	return 0;
}