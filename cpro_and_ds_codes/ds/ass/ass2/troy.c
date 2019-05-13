#include<stdio.h>

#define ll long long int
#define get(n) ll n; if(scanf("%lld", &n))
#define gets(a) char a ; if(scanf("%c", &a))
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

int maxx(int a, int b)
{
	return a>b?a:b;
}


int size=100005;
int stack[100005] = {0};
int top=-1;
void push(int value)
{
	if(top == size-1)
		return;
	else
	{
		top++;
		stack[top] = value;
	}
	return;
}
void pop()
{
	if(top == -1)
		return;
	else {
		top--;
	}
	return;
}
void display()
{
	if(top == -1) 
		return;
	else
	{
		for(int i=top;i>=0;i--)
			printf("%d\n",stack[i]);
	}
	return;
}	


int histo(int arr[] , int n)
{
	int ans  = 0;
	int current = 0;
	int index = 0;

	int i = 0;
	for ( i = 0; i < n; )
	{
		if(top == -1 || arr[stack[top]] <= arr[i])
			push(i++);
		else
		{
			index = stack[top];
			pop();

			if(top == -1)
				current = arr[index]*i;
			else
				current = arr[index]*(i-stack[top]-1);

			ans = ans>current?ans:current;
		}
	}

	while(top != -1)
	{
		index = stack[top];
		pop();
		if(top == -1)
			current = arr[index]*i;
		else
			current = arr[index]*(i-stack[top]-1);
		ans = ans>current?ans:current;
	}
	return ans;
}

int main()
{
//	get(m);
//	get(n);
	int n,m;
	int final  = 0;
	int ans[1005] = {0};
	scanf("%d %d", &m,&n);
	for (int i = 0; i < m; ++i)
	{
		//printf("i is %d\n" ,i);
		int arr[1005] = {0};
		for (int j=0;j < n; ++j)
		{
			//printf("j is %d\n", j );
			char a,temp;
			scanf("%c%c", &temp,&a);
			if(a == 'T')
				arr[j]=1;
			else if(a == 'E')
				arr[j]=0;

			if(arr[j] == 0)
				ans[j] = 0;
			else
				ans[j]++;
		
		}
		/*for (int J = 0; J < n; printf("%d ", arr[J]), ++J);
		printf("\n");
		printf("I am done printing my arrat\n");*/
		// we  now have a histogram ready array
		
		final = maxx(final, histo(ans, n));
		//printf("final is %d\n",final );
	}
	printf("%d\n",final);
	return 0;
}