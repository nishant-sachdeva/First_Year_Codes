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

vector<pair<int,int>> adj[7000009];
int dist[7000009];
bool visited[7000009];
deque<pair<int,int>> vertices;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.precision(10);
    cout<<fixed;
    ////////////////////////////////
 	get(n);
 	get(m);
 	get(p);
 	for (int i = 1; i <= m; ++i)
 	{
 		get(a);
 		get(b);
 		get(c);
 		adj[a].push_back(make_pair(b,1-c));
 		adj[b].push_back(make_pair(a,1-c));
 	}
 	get(x);
 	get(y);
 	// so we have the graph ready now
 	for (int i = 1; i <=n; ++i)
 	{
 		visited[i] = false;
 		dist[i] = inf;
 	}
 	dist[x] = 0;
 	vertices.push_front(make_pair(x,0));
 	while(!vertices.empty())
 	{
 		int a = vertices.front().first;
 		vertices.pop_front();
 		for (int i = 0; i < int(adj[a].size()); ++i)
 		{
 			int b = adj[a][i].first;  //this is the node
 			int d = adj[a][i].second; // this is the edge
 			if(dist[a] + d < dist[b])
 			{
 				dist[b] = dist[a] + d; // dist relaxed
 				if(d == 1)
 					vertices.push_back(make_pair(b,dist[b]));
 				else
 					vertices.push_front(make_pair(b, dist[b]));
 			}
 		}
 	}
 	// for (int i = 1; i <= n; ++i)
 	// {
 	// 	 cout << i << " : " << dist[i] << endl;
 	// }
 	if(dist[y] < inf)
 		cout << dist[y]*p << endl;
 	else
 		cout << -1 << endl;
    return 0;
}