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
vector<int> adj[1000000], ulta_adj[1000000];
bool visited[1000000];
int arr_for_dfs[1000000] = {0};


void dfs(int a)
{
	visited[a] = true;
	for (int i = 0; i <  int(adj[a].size()) ; ++i)
	{
		if(visited[adj[a][i]] == false)
			dfs(adj[a][i]);
	}
	stack_for_dfs.push(a);
	return;
}

void dfs_for_scc(int a)
{
	visited[a] = true;
	// cout << a << " ";
	// arr_for_dfs[a] = 1;
	for (int i = 0; i < int(ulta_adj[a].size()); ++i)
	{
		if(visited[ulta_adj[a][i]] == false)
		{
			arr_for_dfs[ulta_adj[a][i]] = 1;
			arr_for_dfs[a] = 1;
			dfs_for_scc(ulta_adj[a][i]);
		}
	}
	return;
}

int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; ++i)
		visited[i] = false;
	for (int i = 1; i <= n; ++i)
		arr_for_dfs[i] = 0;

	for (int i = 1; i <= m; ++i)
	{
		get(a); get(b);
		adj[a].push_back(b);
		ulta_adj[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		if(visited[i] == false)
			dfs(i);
	}
	// topo sort ho gya hai, ab graph ulta kar do
	// adj list available hai, usseh use kar lena
	for (int i = 1; i <= n; ++i)
	{
		visited[i] = false;
	}
	while(!stack_for_dfs.empty())
	{
		int a = stack_for_dfs.top();
		if(visited[a] == false)
			dfs_for_scc(a);
		// cout << endl;
		stack_for_dfs.pop();
	}
	for (int i = 1; i<=n ; ++i)
	{
		cout << arr_for_dfs[i] << " ";
	}
	cout << endl;

    return 0;
}