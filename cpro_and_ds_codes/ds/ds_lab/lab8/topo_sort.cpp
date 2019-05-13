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

stack<int> stack_for_dfs;
vector<int> adj[100];
bool visited[100];

void dfs(int a)
{
	visited[a] = true;
	for (int i = 0; i <  adj[a].size() ; ++i)
	{
		if(visited[adj[a][i]] == false)
			dfs(adj[a][i]);
	}
	stack_for_dfs.push(a);
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; ++i)
		visited[i] = false;

	for (int i = 0; i < n; ++i)
	{
		get(a); get(b);
		adj[a].push_back(b);
	}
	for (int i = 1; i < n; ++i)
	{
		if(visited[i] == false)
			dfs(i);
	}
	while(!stack_for_dfs.empty())
	{
		cout << stack_for_dfs.top() << endl;
		stack_for_dfs.pop();
	}
    return 0;
}