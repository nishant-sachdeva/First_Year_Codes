#include<stdio.h>
#include<stdlib.h>


#define ll long long int
#define get(n) ll n; if(scanf("%lld", &n))
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
//qsort(arr, n, sizeof(int), compare);

int main()
{
	get(test);
	int arr[100000];
	while(test--)
	{
		get(n);
		for (int i = 0; i < n; ++i)
		{
			get(ni);
			arr[i] = ni;
		}
		qsort(arr, n, sizeof(int), compare);
		for (int i = 2; i < n; i += 2)
		{
			// swap arr[i] and arr[i-1]
			int temp = arr[i];
			arr[i] = arr[i-1];
			arr[i-1] = temp;
		}
		for (int i = 0; i < n; ++i)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	return 0;
}