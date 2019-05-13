#include<stdio.h>


#define ll  long long
#define get(n) ll n; scanf("%lld", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)


ll arr[10000];

ll n,m , final_sum=0;

ll check (ll val)
{
	ll sum=0, count =0;
	for(ll i = 0; i<m ; i++)
	{
		if(arr[i]>val) return 0;
		sum += arr[i];
		if(sum > val)
		{ 
			count++; 
			sum = arr[i]; 
		}
	}
	if(sum <=val)
		{ 
			count++; 
		}
	if( count > n ) return 0;
	else  return 1;

}



ll lower_bound(ll left, ll right)
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
}

int main()
{
	get(test);
	while(test--)
	{
		scanf("%lld %lld", &n, &m);
		get(a); get(b);
		get(mod);
		arr[0] = 1;
		arr[1] = 2;
		ll min = arr[0], final_sum = arr[0] + arr[1];
		for (ll i= 2; i < m; ++i)
		{
			arr[i] = (arr[i-1]*a + a*b + arr[i-2]*b)%mod + b;
			min = min < arr[i]?min:arr[i];
			final_sum += arr[i];
		}
		//for(int i =0 ; i<m; i++) { show(arr[i]);}
		//printf("final sum is %lld and min is %lld  \n", final_sum, min );
		ll ans = lower_bound(1, final_sum+1);
		//for(int i=0;i<final_sum+1;i++) printf("%d : %lld\n",i,check(i));
		show(ans);
	}
	

	return 0;
}