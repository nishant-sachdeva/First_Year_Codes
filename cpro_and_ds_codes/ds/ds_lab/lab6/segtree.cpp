#include<bits/stdc++.h>


#define ll long long int
#define sz(a) ll(a.size())
#define get(a) ll a ; cin >> a
#define vec(A) vector <A>
#define pb push_back
#define full(p) p.begin(),p.end()
#define show(a) cout << a <<'\n'
#define eb emplace_back
#define nl '\n'


using namespace std;

template<typename T> T maxm(T x,T y) {return (x>y)?x:y;}
template<typename T> T mod(T x) {return (x>0)?x:-x;}

ll seg_tree[1000006];
void build_tree(ll arr[] , ll n , ll i = 0)
{
	for (i = 0; i < n; ++i)
	{
		if(arr[i]%2 == 0)
			seg_tree[n+i] = 0;
		else
			seg_tree[n+i] = 1;
	}
	// this tells if a number is odd or even;
	for (i = n-1 ; i>0 ;seg_tree[i] = seg_tree[i<<1] + seg_tree[i<<1|1] , i--);
	// this will give the number of odd and even numbers in a range;
}

void update(ll n , ll index , ll val )
{
	index += n;
	if(val%2 == 0)
		seg_tree[index] = 0;
	else
		seg_tree[index] = 1;
	for (ll i = index ; i > 1 ;seg_tree[i>>1] = seg_tree[i] + seg_tree[i^1] , i>>=1);
	// this updates the val of the number of odd or even numbers;
}

ll get_sum(ll n, ll left , ll right, ll sum = 0)
{
	for (left+=n, right+=n ; left<=right ; left>>=1, right>>=1)
	{
		if(left&1) sum+=seg_tree[left++];
		if((right^1)&1)sum+=seg_tree[right--];
	}
	return sum;
}

/* in case of min query , make appropriate changes */



int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.precision(10);
    cout<<fixed;
    ////////////////////////////////
    get(n);
    ll arr[1000006];
    for (int i = 0; i < n; ++i)
    {
    	get(ni);
    	arr[i] = ni;
    }
    build_tree(arr, n);
    get(m);
    for (int i = 0; i < m; ++i)
    {
    	get(mi);
    	if(mi == 0)
    	{
    		get(x);
    		get(y);
    		update(n,x-1,y);
    	}
    	else if(mi == 1)
    	{
    		get(x);
    		get(y);
    		ll ans = get_sum(n,x-1, y-1);
    		cout << y-x+1 - ans << endl;
    	}
    	else if (mi == 2)
    	{
    		get(x);
    		get(y);
    		ll ans = get_sum(n, x-1, y-1);
    		cout<< ans << endl;
    	}
    }
    return 0;   
    return 0;
}