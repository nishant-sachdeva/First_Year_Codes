#include<bits/stdc++.h>


#define ll long long int
#define sz(a) ll(a.size())
#define get(a) ll a ; cin >> a
#define pb push_back
#define full(p) p.begin(),p.end()
#define show(a) cout << a <<'\n'
#define eb emplace_back
#define nl endl;


using namespace std;


long long int odd_tree[10000007], even_tree[10000007], arr[10000007];
long long int height[10000007], weight[10000007];
std::vector<long long int> adj[10000007];
std::vector<pair<long long int,long long int>> timings(10000007);
bool visited[10000007];

void build_tree(long long int seg_tree[], long long int arr[] , long long int n , long long int i = 0)
{
	for (i = 0; i < n; seg_tree[n+i] = arr[i+1] , ++i);
	for (i = n-1 ; i>0 ;seg_tree[i] = seg_tree[i<<1] + seg_tree[i<<1|1] , i--);
}

void update(long long int seg_tree[], long long int n , long long int index , long long int val )
{
	index += n;
	seg_tree[index] += val;
	for (long long int i = index; i > 1; seg_tree[i>>1] = seg_tree[i] + seg_tree[i^1] , i>>=1);
}

long long int get_sum(long long int seg_tree[], long long int n, long long int left , long long int right, long long int sum = 0)
{
	for (left += n, right+=n ; left > 0 && left <= right ; left>>=1, right>>=1)
	{
		if(left&1) sum+=seg_tree[left++];
		if((right^1)&1)sum+=seg_tree[right--];
	}
	return sum;
}

/* in case of min query , make appropriate changes */

long long int timing = 1;

void dfs(long long int ver, long long int h)
{
	height[ver] = h;
	visited[ver] = true;
	long long int start = timing;
	for(auto neigh : adj[ver])
	{
		if(visited[neigh])
			continue;
		timing++;
		dfs(neigh, h+1);
	}
	timing++;
	long long int end = timing;
	timings[ver] = make_pair(start, end);
	// this should allocate the start and end time of the vertex
	arr[start] = 0;
	arr[end] = 0;
	// this should be able to fill up the entire thing with our stuff
	return;
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.precision(10);
    cout<<fixed;
    ////////////////////////////////
 	get(n);
 	get(m);
 	for (long long int i = 1; i <= n; ++i)
 	{
 		get(ni);
 		weight[i] = ni;
 	}
	/* so the idea is this, */ 

 	// now we get the edges
 	for (long long int i = 1; i <= n-1; ++i)
 	{
 		get(ni);
 		get(mi);
 		adj[ni].push_back(mi);
 		adj[mi].push_back(ni);
 	}
 	// yeh aa gya tree
 	dfs(1,1);
 	// vertex 1 at height 1
 	// doing the dfs for the start,finish times and the height
 	// build segment tree
 	// note seg tree 0 based hai, uske according times dena
 	build_tree(odd_tree, arr, 2*n);
 	build_tree(even_tree, arr,2*n);
 	// for (long long int i = 1; i <= 2*n; ++i)
 	// {
 	// 	// cout << "height of node "<< i << " is " << height[i] << " ";
 	// 	// cout << "start time is " << timings[i].first << " " << "and the end time is " << timings[i].second << endl;
		// cout << arr[i] <<  " "; 		
 	// }
 	// cout << nl;

 	for (long long int i = 0; i < m; ++i)
 	{
 		// here start the queries
 		get(a);
 		if(a == 1)
 		{
 			get(x); // x is the vertex
 			get(v); // v is the amount to be added to x
 			// now here's the logic
 			/*
			agar_bande_ki_height == odd
			{ 
				even_tree.update(start -= v)
				even_tree.update(end += v)
				odd_tree.update(start += v)
				odd_tree.update(end -= v)
 			}
 			else
 			{
				even_tree.update(start += v)
				event_tree.update(end -= v)
				odd_tree.update(start -= v)
				odd_tree.update(end += v)
 			}
 			*/
 			if(height[x]%2 == 1)
 			{
 				// maane height is odd
 				update(even_tree, n*2 , timings[x].first-1, -v);
 				update(even_tree, n*2 , timings[x].second-1, v);
 				update(odd_tree, n*2 , timings[x].first -1, v);
 				update(odd_tree, n*2 , timings[x].second -1, -v);
 			}
 			else if(height[x]%2 == 0)
 			{
 				// maane even hai
 				update(even_tree, n*2 , timings[x].first-1, v);
 				update(even_tree, n*2 , timings[x].second-1, -v);
 				update(odd_tree, n*2 , timings[x].first -1, -v);
 				update(odd_tree, n*2 , timings[x].second -1, v);
 			}
 		}
 		else if(a == 2)
 		{
 			get(x);
 			/* code goes here*/
 			/*logic is:
				get sum from 1-1 to vertex.start -1
				if( height == odd)
					odd tree wala sum
				else
				 	even tree wala sum 
				add to it the weight of the element
				cout << sum << endl;
 			*/
 			if(height[x]%2 == 1)
 			{
 				ll sum = get_sum(odd_tree ,n*2, 0, timings[x].first-1);
 				sum += weight[x];
 				cout << sum << endl;
 			}
 			else if(height[x]%2 == 0)
 			{
 				ll sum = get_sum(even_tree ,n*2, 0, timings[x].first-1);
 				sum += weight[x];
 				cout << sum << endl;
 			}
 		}
 	}
    return 0;
}