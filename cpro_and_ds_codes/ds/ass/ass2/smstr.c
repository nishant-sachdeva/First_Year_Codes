#include<stdio.h>
#include<string.h>
#include <stdlib.h>


#define ll long long int
#define get(n) ll n; if(scanf("%lld", &n))
#define gets(n) char n ; if(scanf("%c", &n))
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)


int size=100005;
char stack[100005];
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
char pop()
{
	if(top == -1)
		return 0;
	else {
		top--;
	}
	return stack[top + 1];
}
void display()
{
	if(top == -1) 
		return;
	else
	{
		for(int i=top;i>=0;i--)
			printf("%c\n",stack[i]);
	}
	return;
}	

int main()
{
	get(n);
	char str[100005];
	scanf("%s", str);
	for (int i = 0; i < n; ++i)
	{
		push(str[i]);
		int check  = 1;
		while(check == 1 && (top > -1))
		{
			char a = stack[top];
			for (int j = i+1; j < n; ++j)
			{
				if(str[j] < a) 
				{
					check = 0;
					break;
				}
			}
			if(check == 1) // i.e there's nothing smaller than this
				printf("%c", pop());
		}
	}
	if(top != -1)
	{
		while(top >= 0)
			printf("%c" , pop());
	}
	printf("\n");
	return 0;
}