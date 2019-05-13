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
#define inf 1e9

using namespace std;

template<typename T> T maxm(T x,T y) {return (x>y)?x:y;}
template<typename T> T mod(T x) {return (x>0)?x:-x;}

std::vector<pair<ll, ll>> adj[1000006];
std::vector<pair<ll, ll>> final(1000006);
std::vector<ll> dist(1000006);
bool visited[1000006];



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
 		get(w);
 		adj[a].push_back(make_pair(w,b));
 		adj[b].push_back(make_pair(w,a));
 	}
 	for (ll i = 0; i < n; ++i)
 	{
 		dist[i] = inf;
 		final[i].first = inf;
 		final[i].second = inf;
 		visited[i] = false;
 	}

 	priority_queue<pair<ll, ll>> q;

 	for (ll i = 0; i < k; ++i)
 	{
 		get(a);
 		// now this is a source node;
 		final[a].first = final[a].second = 0;
 		dist[a] = final[a].second;
 		q.push(make_pair(-dist[a], a));
 	}
 	// so the queue has been initialised for the djikstras, 
 	// here we go, 
 	while(!q.empty())
 	{
 		ll d = -q.top().first; // dist, that is now positive;
 		ll a = q.top().second;
 		q.pop();
 		if(visited[a])
 			continue;
 		visited[a] = true;

 		// now we start the loop

 		for (int i = 0; i < int(adj[a].size()); ++i)
 		{
 			ll b = adj[a][i].second; //  node hai
 			ll w = adj[a][i].first; // edge weight hai

 			ll distt = w + d;

 			// now the idea is to find the appropriate position for the dist
 			// and then assign the value of the second min dist to dist[b] and 
 			// push it onto the queue;
 			ll t1 = final[b].first;
 			ll t2 = final[b].second;
 			vector<ll> arr{ t1, t2, distt };
 			sort(full(arr));
 			final[b].first = arr[0];
 			final[b].second = arr[1];
 			dist[b] = final[b].second;

 			q.push(make_pair(-dist[b], b));
 		}
 	}

 	// apparently after the whole process, 
 	ll a = final[0].second;
 	if(a >= inf)
 		cout << -1 << endl;
 	else
 		cout << final[0].second << endl;
    return 0;
}