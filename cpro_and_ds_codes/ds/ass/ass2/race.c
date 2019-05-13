#include<stdio.h>
#include<stdlib.h>

#define ll long long int
#define get(n) ll n; if(scanf("%lld", &n))
#define gets(n) char n ; if(scanf("%c", &n))
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

ll queue[1000009], start[1000005], speed[1000005];
ll front = 0; // queue will be enqueued here.
ll rear = 0; // queue will be dequeued here.

ll minn = 1e9;

void enqueue(ll x)
{
	queue[front] = x;
	front++;
	return;
}

ll dequeue()
{
	if(front > rear)
	{
		rear++;
		return queue[rear-1];
	}
	return -1;
}

ll popo()
{
	front--;
	return queue[front+1];
}

ll size()
{
	return (front - rear);
}

ll top()
{
	if(front > 0)
		return queue[front-1];
	return queue[front];
}

ll bottom()
{
	return queue[rear];
}


void display()
{
	for (int i = rear; i < front; ++i)
	{
		printf("%lld\n",queue[i]);
	}
	return;
}

ll position[1000005] = {0};

/*ll is_passed(ll n, ll k, ll th,ll time)
{
	//printf("\n%lld: ", time );
	front = 0;
	rear = 0;
	for (int i = 0; i < n; ++i)
	{
		position[i] = start[i] + time*speed[i];
	} // okay, so the position array is ready;

	int i = 0;
	enqueue(i); 
	for ( i = 1; i < k; ++i)
	{
		while( (size() > 0)  && (position[top()] <= position[i]) )
		{
			popo();
		}
		enqueue(i); 
		// am pushing the index here, so that we can remove it as and when required
	}


	//display();

	// here j = k , i = 1 are the two delimiters for the range of k elements
	ll sum = position[top()] ; // we intialize it i
	for (; i < n ; i++)
	{
		//printf("loop 2\n");
		
		//printf("%lld ", sum);

		while((i-k) >= top() &&  (size() > 0)) // we don't want garbage returning;
		{
			//printf("hi again\n");
			dequeue();
		}
		// this removed the top elements that are not part of the range
		while((position[top()] <= position[i])  && (size() > 0))
		{
			//printf("hi thrice\n");
			popo();
		}
		enqueue(i);
		sum += position[top()] ;

	}
	//printf(" %lld ",sum );

	// so, I assume that the final requirements is there,

	if(sum > th)
	{
		//printf("%lld we're passing it\n", time);
		return 1;
	}
	//printf("%lld we're not  pasasing it\n", time );
	return 0;
}
*/


ll alt(ll n, ll k , ll th, ll time)
{
	for (int i = 0; i < n; ++i)
	{
		position[i] = start[i] + time*speed[i];
	} // okay, so the position array is ready;

	ll sum = 0;
	for (int i = 0; i < n-k+1; ++i)
	{
		ll maxx = 0;
		for (int j = i; j <= i+k-1; ++j)
		{
			maxx = maxx > position[j]?maxx:position[j];
		}
		sum += maxx;
	}

	if(sum > th)
		return 1;
	return 0;
}

void search(ll n, ll k, ll th , ll l, ll u)
{
	while(u>=l)
	{
		ll test = (u+l)/2;

		/*ll a = is_passed(n, k, th, test);

		// returns 1 if yes nd other wise a 0;
		if(a == 1)
		{
			ll check = is_passed(n,k,th,test-1);
			if(check == 0a)
				return test;
			else
				u = test;
		}
		else if(a == 0)
		{
			ll check = is_passed(n,k,th,test+1);
			if(check == 1)
				return (test+1);
			else
				l = test;
		}*/

		if(alt(n,k,th,test) == 1)
		{
			minn = minn<test?minn:test;
			u = test-1;
		}
		else
			l = test+1;
		//if(is_passed(n,k,th,test) && !is_passed(n,k,th,test-1)) return test;
		//if(!is_passed(n,k,th,test)) l=test+1;
		//else u=test;
	}
	/*for (int i = 0; i < 1000000009; ++i)
	{
		ll a = is_passed(n,k,th,i);
		if(a == 1)
			return i;
	}*/
	return ;
}



/*ll lower_bound(ll left, ll right)
{
	ll mid;
	while(right - left>1)
	 {
		mid = (left + right )/2;
	//	printf("we are in the bianry search , mid is %lld\n", mid );
	// 	if(!check(mid))
	// 		left = mid+1;
	// 	else 
	// 		right = mid;
		if(check(mid) && !check(mid-1)) return mid;
		if(!check(mid)) left=mid+1;
		else right=mid;

	}
	return left;
}*/



int main()
{
	get(n);
	get(k);
	get(th);
	for (int i = 0; i < n; ++i)
	{
		get(ni);
		start[i] = ni;
	}

	for (int i = 0; i < n; ++i)
	{
		get(ni);
		speed[i] = ni;
	}
	// in the linked list, the head is the left side and the p is the right side;
	search(n, k, th, -1 , 1e9);
	printf("%lld\n",minn);

	return 0;
}
