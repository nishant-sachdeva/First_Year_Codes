#include<bits/stdc++.h>
#define get(a) int a ; scanf("%d", &a)
#define vc vector <int>
#define loop(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define full(p) p.begin(),p.end()
#define show(a) printf("%d\n", a);
#define eb emplace_back
using namespace std;

template<typename T> T maxm(T x,T y) {return (x>y)?x:y;}


std::vector<int> adj[100];
bool visited[100];
bool vis_bfs[100];

int color[100] = {0};

/*void dfs(int start){
	visited[start]=1;  
	for(int i=0; i<vec[start].size();i++){
		if(visited[vec[start][i]] != 1){
			dfs(vec[start][i]);
		}
	}
	return ;
}*/

/*queue <int> q;


void bfs(int start, int col)
{
    // we have the element jhaan seh hum bfs shuru karengeh;
    while(!q.empty())
    {
        int element = q.front();
        for (int i = 0; i <vec[element].size() ; ++i)
        {
            // if the guy hasn't been visited before then push;
            if(vis[vec[element][i]] != 1)
                q.push(vec[element][i]);
            else{
                if(color[ vec[element][i] ] == col)
                {
                    cout << 0 << nl;
            }
        }
        vis_bfs[element] = 1;
        color[element] = col; 
        q.pop();
        col = 1-col;
        // this has pushed the guy's kids into the adj list
    }
}
*/

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.precision(10);
    cout<<fixed;
    ////////////////////////////////
    get(edges);
    get(nodes);
    //now, for the input;
    for(int i=0 ; i<edges; i++){
    	get(a);get(b);
    	vec[a].pb(b);
    	vec[b].pb(a);
    }

    for (int i = 0; i < nodes; ++i)
    {
        // agar woh visit nai hua toh dfs lagao bhai pe;
        if(visited[i] != 1)
            dfs(i);
    }

    /*for (int i = 0; i < nodes; ++i)
    {
        if(vis_bfs[i] != 1)
            bfs(i, 0);
    } */   
    return 0;
}


