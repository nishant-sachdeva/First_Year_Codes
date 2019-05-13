#include<stdio.h>

#define ll long long int
#define get(n)  ll n; if(scanf("%lld", &n))
#define gets(n) char n ; if(scanf("%c", &n))
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)


void merge(ll arr[] , ll arr2[], ll left, ll mid, ll right)
{
		ll n1 = mid-left + 1;
		ll n2 = right-mid;
		ll l[n1], l2[n1],r2[n2] , r[n2];
		for(ll i = 0 ; i<n1 ;i++)
		{
				l[i] = arr[left+i];
				l2[i]= arr2[left+i];
		}
		for(ll i = 0 ; i<n2 ; i++)
		{
				r[i] = arr[mid+1+i];
				r2[i] = arr2[mid+1+i];
		}
		ll k = left, i=0, j=0;
		while(i<n1 && j<n2)
		{
				if(l[i] < r[j])
				{
						arr[k] = l[i];
						arr2[k++] = l2[i++];
				}
				else if(r[j] < l[i])
				{
						arr[k] = r[j];
						arr2[k++] = r2[j++];
				}
				else if(l[i] == r[j])
				{
					if(l2[i] < r2[j])
					{
						arr[k] = l[i];
						arr2[k++] = l2[i++];
					}
					else
					{
						arr[k] = r[j];
						arr2[k++] = r2[j++];
					}
				}
		}
		while(i<n1)
		{
				arr[k] = l[i];
				arr2[k++] = l2[i++];
		}
		while(j<n2)
		{
				arr[k] = r[j];
				arr2[k++] = r2[j++];
		}
		return;
}

void mergesort( ll arr[], ll arr2[], ll left, ll right)
{
		if(left < right)
		{
				ll mid = (left + right)/2;
				mergesort(arr, arr2 , left , mid);
				mergesort(arr, arr2 , mid+1, right);
				merge(arr, arr2,  left , mid, right);
		}
		return ;
}

ll p_garb[1000006], q_garb[1000006];
ll p[1000006], q[1000006];


ll calc(ll n)
{
	if(n<3)return 0;
	ll ans = 1;
	ans = (n*(n-1))/2;
	ans *= n-2;
	ans /= 3;
	return ans;
}

int main()
{
	get(n);
	get(mod);
	for (ll i = 0; i < n; ++i)
	{
		get(pi);
		get(qi);
		
		p_garb[i] = pi;
		q_garb[i] = qi;
	}
	mergesort( p_garb, q_garb, 0, n-1);

	//now i have the list of all the points in sorted order
	//now i will traverse it to find all the unique points;
	p[0] = p_garb[0];
	q[0] = q_garb[0];
	ll temp = 1, count =1 ;
	for(ll i=1 ; i<n ; i++)
	{
		if(p_garb[i] == p_garb[i-1] && q_garb[i] == q_garb[i-1])continue;
		//else
		count++;
		p[temp] = p_garb[i];
		q[temp++] = q_garb[i];
	}

	//for(int i =0 ; i<count ; i++)
	//	printf("%lld %lld\n",p[i], q[i]);

	// now I have all the unique points and the thing is sorted;

	//printf("numebr of distinct points is %lld\n", count);
	ll ans = 0;
	ans += calc(count);
	//printf("intial Nc3 is %lld\n",ans );

	for(ll i = 0 ; i<count ; i++)
	{
		ll c = 1;
		ll temp = p[i];
		while(p[i+1] == temp && i<count)
		{
			c++;
			i++;
		}
		//printf("number of points on the line x = %lld is %lld\n", temp , c );
		temp = calc(c);
		ans -= temp;
		//printf("modified ans is %lld\n", ans );
	}

	mergesort(q, p, 0, count -1);

	for(ll i =0 ; i<count ; i++)
	{
		ll c = 1;
		ll temp = q[i];
		while(q[i+1] == temp && i<count)
		{
			c++;
			i++;
		}
		//printf("the number of points on the line y = %lld is %lld\n",temp , c );
		temp = calc(c);
		ans -= temp;
		//printf("modified ans is %lld\n", ans );
	}

	printf("%lld\n", ans%mod);
	return 0;
}