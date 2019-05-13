#include<bits/stdc++.h>
#define get(a) int a ; scanf("%d", &a)
#define vc vector <int>
#define loop(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define full(p) p.begin(),p.end()
#define show(a) printf("%d\n", a);

using namespace std;

template<typename T> T max(T x,T y) {return (x>y)?x:y;}


bool visited[150];

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.precision(10);
    cout<<fixed;
    ////////////////////////////////

    vc vec[100];
    // yhaan peh 
    get(n);
    get(edges);
    for(int i=0 ; i<edges; i++)
    {
        get(v1);
        get(v2);
        vec[v1].pb(v2);
        vec[v2].pb(v1);
    }
    // i hv the graph;

    /* vector <bool> visited[100];
       {
       visited[i] =1;
       }*/
    //further code is for bfs;
    int d=0;
    vector <int> dist[100];
    dist[0].pb(0);//i am assuming that the root is 0, dist 0 is the first row, the other 0 is the root;

    for(d=0; d<n; d++)
    {
        for(int i=0; i<dist[d].size(); i++)
        {
            visited [ dist[d][i] ] = 1;
            for(int j=0; j<vec[dist[d][i]].size(); j++)
            {
                if(visited[vec[dist[d][i]][j]] == 1)
                    continue;
                else
                    dist[d+1].pb(vec[dist[d][i]][j]);
            }
        }
    }
    // further code is for bfs;

    loop(d,n)
        loop(i,dist[d].size()){
            visited[dist[d][i]] =1;
            loop(j,vec[dist[d][i]].size()){
                if(visited[vec[dist[d][i]][j]] != 1)
                    dist[d+1].pb(vec[dist[d][i]][j]);
            }
         }

    // further code is for dfs
    return 0;
}


