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

int seg_tree[1000];
void build_tree(int arr[] , int n , int i = 0)
{
	for (i = 0; i < n; seg_tree[n+i] = arr[i] , ++i);
	for (i = n-1 ; i>0 ;seg_tree[i] = seg_tree[i<<1] + seg_tree[i<<1|1] , i--);
}

void update(int n , int index , int val )
{
	index += n;
	seg_tree[index] = val;
	for (int i = index ; i > 1 ;seg_tree[i>>1] = seg_tree[i] + seg_tree[i^1] , i>>=1);
}

int get_sum(int n, int left , int right, int sum = 0)
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
	get(m);
	for (int i = 0; i < m; ++i)
	{
		get(x);
		get(y);
		// yeh two ranges hain jhaan update karna hai;
	}
	get(q);
	for (int i = 0; i < q; ++i)
	{
		get(qi);
		ll ans = solve();
	}
    return 0;
}