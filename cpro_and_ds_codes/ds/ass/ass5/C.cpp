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

std::vector<pair<int,int>> adj[7000009];
priority_queue<pair<int,int>> reduction;
ll dist[7000009] = {0};
bool visited[7000009];


int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.precision(10);
    cout<<fixed;
    ////////////////////////////////
 	get(nodes);
 	get(edges);
 	get(p);
 	for (int i = 1; i <= edges; ++i)
 	{
 		get(a);
 		get(b);
 		get(c);
 		// dist[a] = inf;
 		// dist[b] = inf;
 		// visited[i] = false;
 		if(c == 1)
 		{
 			adj[a].push_back(make_pair(b,0));
 			adj[b].push_back(make_pair(a,0));
 		}
 		else
 		{
 			adj[a].push_back(make_pair(b,p));
 			adj[b].push_back(make_pair(a,p));
 		}
 	}
 	// this completes our adj list;
 	get(x);
 	get(y);
 	for (int i = 1; i <= nodes; ++i)
 	{
 		dist[i] = inf;
 		visited[i] = false;
 	}
 	dist[x] = 0;
 	reduction.push(make_pair(0,x));
 	while(!reduction.empty())
 	{
 		// cout << "hi" << endl;
 		ll a = reduction.top().second; // vertex hai
 		if(a == y)
 			break;
 		reduction.pop();
 		if(visited[a] == true)
 			continue;
 		visited[a] = true;
 		
 		// here i have the guy with the min dist
 		for (int i = 0; i < int(adj[a].size()); ++i)
 		{
 			ll b = adj[a][i].first;
 			ll d = adj[a][i].second;
 			// now we'll reduce
 			if(dist[a] + d < dist[b])
 			{
 				dist[b] = dist[a] + d;
 				reduction.push(make_pair(-dist[b] , b));
 				// so here we added the edge and the element to the p  queue
 			}
 		}
 	}
 	// now this should complete our djikstra's 
 	// we'll output the dist now
 	if(dist[y] < inf)
 	{
 		// means woh reduce hua hai
 		// printf("%lld\n",dist[y]);
 		cout << dist[y] << nl;
 	}
 	else
 		cout << -1 << nl;


    return 0;
}