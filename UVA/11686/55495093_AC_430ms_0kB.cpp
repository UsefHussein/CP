#include <complex.h>
#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(x) x.size()

const int N=1e6+1;

vector<int>adj[N],topo;

bool vis[N],iscycle[N];

int dis[N];

bool bo=1;
void dfs(int x)
{
    vis[x]=1;
    iscycle[x]=1;
    for(int y:adj[x])
    {
        if(!vis[y])
        {
            dis[y]=dis[x]+1;
            dfs(y);
        }
        else {
            if(iscycle[y])bo=0;
        }
    }
    iscycle[x]=0;
    topo.push_back(x);
}
void $olve()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(!n)return;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
        reverse(topo.begin(),topo.end());
        if(!bo)cout<<"IMPOSSIBLE"<<enl;
        else for(auto i:topo)cout<<i<<enl;
        for(int i=0;i<=n;i++)adj[i].clear();
        topo.clear();
        bo=1;
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        memset(iscycle,0,sizeof(iscycle));
    }
}
void F_F()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

signed main()
{
    F_F();
    int T = 1;
    //cin>>T;
    while(T--)$olve();
    return 0;
}