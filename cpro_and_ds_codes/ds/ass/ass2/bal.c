#include<stdio.h>

#define ll long long int
#define get(n) ll n; if(scanf("%lld", &n))
#define gets(n) char n ; if(scanf("%c", &n))
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

int size=100005;
int stack[100005];
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
	get(n);// n is the size of the string
	size = n; 
	char string[100005]={0};
	scanf("%s", string);

	if(n&1)
		printf("-1\n");
	else
	{
		int change = 0;
		for (int i = 0; i < n; ++i)
		{
			if(string[i] == 'A')
				push('A');
			else if(string[i] == 'C')
			{
				if(top == -1) // which means the stack is empty;
				{
					push('A');
					change++;
				}
				else if(stack[top] == 'A')
				{
					pop(); // mea/ns everything is all well
				}
			}
		}
		// now there can definitely be no C's but there can be A's, so
		change += (top+1)/2;
		printf("%d\n",change );
	}
	return 0;
}