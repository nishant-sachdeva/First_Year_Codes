#include<stdio.h>

#define ll long long int 
#define get(n) ll n; scanf("%lld", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

ll store[1005]={0};
ll arr[1001][1001]={0};

ll upper_bound( ll key , ll arr[] , ll left , ll right) // upper bound binarysearch
{
	//printf("In upper bound \nkey is %lld\n left is %lld\n right is %lld\n", key, left, right);
	long long int mid;
	while( left < right )
	{
		mid = (left + right)/2;
		if(key < arr[mid])
			right = mid;
		else 
			left = mid +1;	
	}
	return left;
}

ll lower_bound ( ll key , ll arr[] , ll left, ll right) //lower bound binary search
{
	//printf("In lower bound, \nkey is %lld\n left is %lld\n right is %lld\n", key, left, right);
	long long int mid;
	while( left < right)
	{
		mid  = ( left + right)/2;
		if( key <= arr[mid])
			right =mid;
		else
			left = mid + 1;
	}
	//if( arr[left] == key) return left;
	return left;
}


int main()
{
    get(n) ; get(q);
    for (ll i = 1; i <=n; ++i)
    {
    	get(ni);
    	arr[ni][++store[ni]]=i;
    }
    for(ll i = 1 ; i<=q ; i++)
    {
    	get(left); get(right); get(sum); 
    	ll count =0 , dj=0, dsj=0;
    	for(ll j = 1 ; 2*j<= sum ; j++)
    	{
    		if(sum - j > 1000) 
    			continue;
    		else
    		{
    			ll djr = upper_bound( right, arr[j], 0, store[j]+1);
    			ll djl = lower_bound( left , arr[j], 0, store[j]+1);

    			//printf("upper bound returns %lld\n", djr );
    			//printf("lower bound returns %lld\n", djl );
    			
    			dj = djr - djl;
    			//printf("freq of  %lld is %lld\n",j , dj );


    			ll dsjr = upper_bound(right , arr[sum-j] , 0 , store[sum-j] + 1);
    			ll dsjl = lower_bound(left  , arr[sum-j] , 0 , store[sum-j] + 1);
    			
    			//printf("upper bound returns %lld\n", dsjr );
    			//printf("lower bound returns %lld\n", dsjl );

    			dsj = dsjr -  dsjl;
    			//printf("freq of  %lld is %lld\n",sum - j, dsj );
  			    
  			    if( 2*j == sum)
    				count += ((dj*(dj-1))/2);
    			else 
    				count += dj*dsj;
    		}
    	}
    	show(count);
    }
    return 0;
}