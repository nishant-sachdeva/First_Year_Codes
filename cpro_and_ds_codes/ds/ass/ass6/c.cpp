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

std::vector<pair<pair<int,int>, pair<int,int>>> vertices(1000006);
std::vector<pair<int, int>>adj[1000006];
std::vector<pair<int, int>> reverse_adj[1000006];

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.precision(10);
    cout<<fixed;
    ////////////////////////////////
 	get(n);
 	get(m);
 	get(s);
 	get(t);
 	for (int i = 0; i < m; ++i)
 	{
 		get(a);
 		get(b);
 		get(w);
 		adj[a].push_back(make_pair(b,w));
 		reverse_adj[b].push_back(make_pair(a,w));
 	}
 	for (int i = 1; i <= n; ++i)
 	{
 		vertices[i].first.first = inf;
 		vertices[i].first.second = inf;
 		vertices[i].second.first = inf;
 		vertices[i].second.second = inf; 		
 	}

 	{
 		// djiktra(s,t,adj);
 		// declarations
 		priority_queue<pair<int, int>>q;
 		bool visited[1000006];
 		for (int i = 1; i <= n ; ++i)
 		{
 			visited[i] = false;
 		}
 		vertices[s].first.first = 0;
 		q.push(make_pair(0,s));
 		while(!q.empty())
 		{
 			int a = q.top().second; // vertex hai
 			q.pop();
 			if(visited[a] == true)
 				continue;
 			visited[a] = true;
 			for (int i = 0; i < int(adj[a].size()); ++i)
 			{
 				int b = adj[a][i].first;  //this is the node
 				int d = adj[a][i].second; // this is the edge
 				if(vertices[a].first.first + d < vertices[b].first.first)
 				{
 					vertices[b].first.first = vertices[a].first.first + d; // dist relaxed
 					q.push(make_pair(-vertices[b].first.first, b));
 				}	
 			}
 		}
 	}
 	// for (int i = 1; i <= n; ++i)
 	// {
 	// 	cout << vertices[i].first.first << " " << vertices[i].first.second << " " << vertices[i].second.first << " " << vertices[i].second.second << endl;
 	// }
 	// that completes the first djikstras
 	{
 		// djiktra(t,s,adj);
 		priority_queue<pair<int, int>>q;
 		bool visited[1000006];
 		for (int i = 1; i <= n ; ++i)
 		{
 			visited[i] = false;
 		}
 		vertices[t].first.second = 0;
 		q.push(make_pair(0,t));
 		while(!q.empty())
 		{
 			int a = q.top().second; // vertex hai
 			q.pop();
 			if(visited[a] == true)
 				continue;
 			visited[a] = true;
 			
 			for (int i = 0; i < int(adj[a].size()); ++i)
 			{
 				int b = adj[a][i].first;  //this is the node
 				int d = adj[a][i].second; // this is the edge
 				if(vertices[a].first.second + d < vertices[b].first.second)
 				{
 					vertices[b].first.second = vertices[a].first.second + d; // dist relaxed
 					q.push(make_pair(-vertices[b].first.second,b));
 				}	
 			}
 		}
 		
 	}
 	// for (int i = 1; i <= n; ++i)
 	// {
 	// 	cout << vertices[i].first.first << " " << vertices[i].first.second << " " << vertices[i].second.first << " " << vertices[i].second.second << endl;
 	// }
 	{
 		// djiktra(s,t,reverse_adj);
 		priority_queue<pair<int, int>>q;
 		bool visited[1000006];
 		for (int i = 1; i <= n ; ++i)
 		{
 			visited[i] = false;
 		}
 		vertices[s].second.first = 0;
 		q.push(make_pair(0,s));
 		while(!q.empty())
 		{
 			int a = q.top().second; // vertex hai
 			q.pop();
 			if(visited[a] == true)
 				continue;
 			visited[a] = true;
 			for (int i = 0; i < int(reverse_adj[a].size()); ++i)
 			{
 				int b = reverse_adj[a][i].first;  //this is the node
 				int d = reverse_adj[a][i].second; // this is the edge
 				if(vertices[a].second.first + d < vertices[b].second.first)
 				{
 					vertices[b].second.first = vertices[a].second.first + d; // dist relaxed
 					q.push(make_pair(-vertices[b].second.first,b));
 				}	
 			}
 		}
 		
 	}
 	// for (int i = 1; i <= n; ++i)
 	// {
 	// 	cout << vertices[i].first.first << " " << vertices[i].first.second << " " << vertices[i].second.first << " " << vertices[i].second.second << endl;
 	// }
 	{
 		// djiktra(t,s,reverse_adj);
 		priority_queue<pair<int, int>>q;
 		bool visited[1000006];
 		for (int i = 1; i <= n ; ++i)
 		{
 			visited[i] = false;
 		}
 		vertices[t].second.second = 0;
 		q.push(make_pair(0,t));
 		while(!q.empty())
 		{
 			int a = q.top().second; // vertex hai
 			q.pop();
 			if(visited[a] == true)
 				continue;
 			visited[a] = true;
 			for (int i = 0; i < int(reverse_adj[a].size()); ++i)
 			{
 				int b = reverse_adj[a][i].first;  //this is the node
 				int d = reverse_adj[a][i].second; // this is the edge
 				if(vertices[a].second.second + d < vertices[b].second.second)
 				{
 					vertices[b].second.second = vertices[a].second.second + d; // dist relaxed
 					q.push(make_pair(-vertices[b].second.second,b));
 				}	
 			}
 		}
	}
	// for (int i = 1; i <= n; ++i)
 // 	{
 // 		cout << vertices[i].first.first << " " << vertices[i].first.second << " " << vertices[i].second.first << " " << vertices[i].second.second << endl;
 // 	}
 	ll ans = inf;
 	for (int i = 1 ; i<=n ; i++)
 	{
 		if(vertices[i].first.first == inf)
 			continue;
 		else if(vertices[i].first.second == inf)
 			continue;
  		else if(vertices[i].second.first == inf)
 			continue;
 	 	else if(vertices[i].second.second == inf)
 			continue;
 		else if (i == s || i == t)
 			continue;
 		// since i am here,  it means abi sum hai
 		ll sum = vertices[i].first.first + vertices[i].first.second + vertices[i].second.first + vertices[i].second.second;
 		ans = min(ans, sum);
 	}
 	if(ans >= inf)
 		cout << -1 << endl;
 	else
 		cout << ans << endl;
    return 0;
}