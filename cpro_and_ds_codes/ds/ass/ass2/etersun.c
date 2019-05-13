#include<stdio.h>

#define ll long long int
#define get(n) ll n; if(scanf("%lld", &n))

ll queue[1000009];
ll front = 0; // queue will be enqueued here.
ll rear = 0; // queue will be dequeued here.

ll minn = 1e9;

void enqueue(ll x)
{
	queue[rear] = x;
	rear++;
	return;
}

ll dequeue()
{
	if(rear > front)
	{
		front++;
		return queue[front-1];
	}
	return -1;
}

ll pop()
{
	rear--;
	return queue[rear];
}

ll size()
{
	return -(front - rear);
}

ll top()
{
	if(front >= 0)
		return queue[front];
	else
		return -1;
}

ll bottom()
{
	return queue[rear-1];
}


void display()
{
	for (int i = front; i < rear; ++i)
	{
		printf("%lld  ",queue[i]);
	}
	printf("\n");
	return;
}


ll arr[100005], ans[100005] ;

ll pass(ll start, ll range)
{
	front = 0;rear = 0;
	enqueue(start+range);
	// n+1 se leke  n+k tak ak min return karna  hai;
	for(int i = start+range-1 ; i >= (start+1) ; i--)
	{
		while((size() > 0) && (ans[bottom()] > ans[i]))
			pop();
		enqueue(i);
	}
	ans[start] = arr[start] + ans[top()];
	start--;

	//display();
	for(; start>=0 ; start--)
	{
		int i = start + range;
		while(top() > i )
			dequeue();
		while( (size() > 0) && (ans[bottom()] > ans[start+1]))
			pop();
		enqueue(start+1);
		
		//display();
		ans[start] = arr[start] + ans[top()];
	}

	return ans[0];
}


int main()
{
	get(n);
	get(k);
	for(int i = 0; i < n; ++i)
	{
		get(ni);
		arr[i] = ni;
	}
	for (int i = n-k-1; i < n-1; ++i)
	{
		ans[i] = arr[n-1] + arr[i];		
	}
	ans[n-1] = arr[n-1];

	//for (int i = n-k-2; i >= 0 ; i--)

	printf("%lld\n", pass(n-k-2,k));
	return 0;
}