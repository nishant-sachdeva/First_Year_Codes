#include<bits/stdc++.h>


#define ll long long int
#define sz(a) ll(a.size())
#define get(a) ll a ; cin >> a
#define vec(A) vector <A>
#define pb push_back
#define full(p) p.begin(),p.end()
#define show(a) cout << a <<'\n'
#define eb emplace_back
#define nl endl;


using namespace std;

template<typename T> T maxm(T x,T y) {return (x>y)?x:y;}
template<typename T> T mod(T x) {return (x>0)?x:-x;}

std::vector<pair<ll , pair<ll,ll> >> edges;
bool h[10000006]; // to make sure the graph is connected

ll link[10000006], size[10000006];

ll find(ll a)
{
	while(a != link[a])
		a = link[a];
	return a;
	// in the array, link[a] is either the node itself(self parent, or head)
	// or the nearest parent
}

void unite(ll a, ll b)
{
	a = find(a); // head link of a
	b = find(b); // head link of b
	if( size[a] < size[b] )
	{
		ll temp = a;
		a = b;
		b = temp;
	}
	// we have to attach the smaller guy to the bigger one
	// so add the size of the smaller to the bigger and link the smaller head to the bigger
	size[a] += size[b];
	link[b] = a;
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
    get(k);
    for (ll i = 0; i < m; ++i)
    {
    	get(a);
    	get(b);
    	get(c);
    	edges.push_back(make_pair(c, make_pair(a,b)));
    }


    // the following for loop provides for the corner case that the graph is disconnected;

    if(n == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    // now since we've made it till here, we know that the graph is connected;

    for (ll i = 1; i <= n; ++i)
    {
    	link[i] = i;
    	size[i] = 1;
    }
    // union find is initialized;

    sort(full(edges));
    // edges are (weight, node a, node b)
    // hence, sorted by weight
    // cout << "edges have been sorted" << endl;
    // for (int i = 0 ; i < m; ++i)
    // {
    // 	cout << edges[i].second.first << " " << edges[i].second.second << " " << edges[i].first <<endl;
    // }
    ll total_weight = 0;

    stack<ll> mst;

    for (ll i = 0; i < m; ++i)
    {
    	ll a = edges[i].second.first; // first node
    	ll b = edges[i].second.second; // second node
    	ll w = edges[i].first; // weight of the edge;

    	if(find(a) != find(b))
    	{
    		// cout << "edge added to mst " << a << " " << b << " " << w << endl;
    		unite(a,b);
    		total_weight += w;
    		mst.push(w);
    	}
    }
    // so we have the mst ready, 
    /*
    	so here's what we do,
    	keep removing edges and replacing them with a 1 as long as total_weight is greater than k
    	for every iteration, do a ++ on the count;
    	if after the stack goes empty, the sum is still greater than k, prll a -1;  
    */
    // while(!mst.empty())
    // {
    //     cout << mst.top() << endl;
    //     mst.pop();
    // }
    ll iteration = 0;
    ll a = find(1);
    for(int i = 1 ; i<= n ; i++)
    {
        if(find(i) != a)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    while(total_weight > k && !mst.empty())
    {
    	iteration++;
    	ll w = mst.top();
    	mst.pop();
    	total_weight -= w;
    	total_weight += 1;
    }

    if(total_weight > k)
    	cout << -1 << endl;
    else
    	cout << iteration << endl;
    // // cout << total_weight << endl;
    return 0;
}