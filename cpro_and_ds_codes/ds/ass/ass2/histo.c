#include<stdio.h>

#define ll long long int
#define get(n) ll n; if(scanf("%lld", &n))
#define gets(n) char n ; if(scanf("%c", &n))
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

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



int main()
{
	get(n);
	int arr[1000] = {0};
	for (int i = 0; i < n; ++i)
	{
		long long int ni; 
		scanf("%lld", &ni);
		arr[i] = ni;
	}
	// the stack will be used to store the value of the indices;
	int ans = 0;
	int index = 0;
	int current = 0;
	int  i = 0;
	for(i = 0 ; i<n ; )
	{
		if(top == -1 || arr[stack[top]] <= arr[i])
			push(i++);
		else
		{
			index = stack[top];
			pop();
			if(top ==  -1)
				current = arr[index] * i;
			else
				current = arr[index] * (i-stack[top]-1) ;
			ans = ans>current?ans:current;
		}
	}

	while(top != -1)
	{
		index = stack[top];
		pop();
		if(top ==  -1)
			current = arr[index] * i;
		else
			current = arr[index] * (i-stack[top]-1) ;
		ans = ans>current?ans:current;
	}

	printf("%d\n",ans );
	return 0;
}


















