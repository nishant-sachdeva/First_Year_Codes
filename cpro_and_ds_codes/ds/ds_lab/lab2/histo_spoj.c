#include<stdio.h>

#define ll long long int
#define get(n) ll n; if(scanf("%lld", &n))
#define gets(n) char n ; if(scanf("%c", &n))
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

ll size = 0;
ll stack[100005] = {0};
ll top=-1;
void push(int value)
{
	if(top == size-1) printf("Stack is full ,Not Possible\n");
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
		printf("Deleted\n");
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
			printf("%lld\n",stack[i]);
	}
	return;
}	



int main()
{
	while(1)
	{
		for (int i = 0; i < 100005; ++i)
		{
			stack[i] = 0;
		}
		get(n);
		size = n;
		if(n == 0)
			break;
		for (ll i = 1; i <= n; ++i)
		{
			get(ni);
			stack[i] = ni;
		}
		ll ans = 0;
		//now the stack has been created, we will do the question now,
		
	}
	

	return 0;
}