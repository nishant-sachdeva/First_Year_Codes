#include<bits/stdc++.h>


#define ll long long
#define sz(a) ll(a.size())
#define get(a) long long int a ; cin >> a
#define vec(A) vector <A>
#define pb push_back
#define full(p) p.begin(),p.end()
#define show(a) cout << a <<'\n'
#define eb emplace_back
#define nl endl;
#define inf 1e7

using namespace std;

template<typename T> T maxm(T x,T y) {return (x>y)?x:y;}
template<typename T> T mod(T x) {return (x>0)?x:-x;}


long long int po(long long int x, long long int y, long long int p)
{
	// to find x power y mod p
	long long int ans = 1;
	x = x%p;
	while(y > 0)
	{
		if(y%2 == 1)
			ans = (ans*x)%p;
		y  = y/2;
		x = (x*x)%p;
	}
	return ans;
}


vector<pair<long long int, long long int>> adj[1000006];
queue<pair<pair<long long int , long long int>,long long int>> vertices;
bool visited[1000005];
long long int n, ans = 0;


void dfs(long long int node, long long int parent, long long int prev_edge)
{
    // cout << "in dfs now, going to " <<  node << endl;  
    // cout << "current parent is " << parent << endl;
    // cout << "Node is " << node << " parent is " << parent << " edge being passed is "<< prev_edge  << endl;

    ans--;
    visited[node] = true;
    for ( int i = 0; i <  int (adj[node].size()); ++i)
    {
        long long int child = adj[node][i].second;

        if(child == parent || visited[child] == true)
            continue;
        long long int edge = adj[node][i].first;
        // cout << child <<  "  " << edge << endl;
        if(edge == prev_edge)
        {
            // cout << "edge " << edge << " is found to be same as prev_edge " << prev_edge << endl;
            // we have found that the graph
            // finished
            ans = 0;
            return;
        }
        if(visited[child] == false)
            dfs(child, parent, edge);
    }
    return;
}


int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.precision(10);
    cout<<fixed;
    ////////////////////////////////
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
    	get(a);
    	get(b);
    	get(c);
    	adj[a].push_back(make_pair(c,b));
    	adj[b].push_back(make_pair(c,a));
    }
    for (int i = 1; i <= n; ++i)
    {
        visited[i] = false;
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(adj[i].begin(),adj[i].end());
        // sort ho gya
        for (int j = 1; j < int(adj[i].size()); ++j)
        {
            if(adj[i][j].first == adj[i][j-1].first)
            {
                /*we found the same vertices
                push them in the queue,  */
                vertices.push( make_pair ( make_pair( adj[i][j].second, i) , adj[i][j].first ));
                vertices.push( make_pair ( make_pair( adj[i][j-1].second, i), adj[i][j-1].first ));     
            }
        }
        // basically sort the particular adj list, iterate and whatever element repeats
        // add it to the queue, and also we'll need the previous edge to checl if there
        // is a vertical thing, cuz if that happens, we want to stop the algo right there

    }
    // okay so this part works perfectly;
    // i just need to get the graph part right
    ans = n;
    // so for each element in the queue, 
    // perform a dfs, such that each path in it's
    // way is marked as not viable and n reduces 
    // accordingly, after the process, what remains
    // of n is the final ans that we'll process
    // for the exponential funciton
    while(!vertices.empty())
    {
        long long int node = vertices.front().first.first;
        long long int parent = vertices.front().first.second;
        long long int edge = vertices.front().second;
        if(visited[node] == false)
            dfs(node, parent, edge);
        vertices.pop(); 
    }
    // basically agar mujhe koi kharab edge milli
    // then ans ko 0 kar dena hai and dfs khatam
    // karna hai
    // cout << "ans as of now is " << ans << endl;
    if(ans <= 0)
        cout << 0 << endl;
    else
    {
        long long int temp = po(ans, ans, 1e9 + 7-1);
        cout << po(ans, temp ,1e9 + 7) << endl;
    }
    return 0;
}