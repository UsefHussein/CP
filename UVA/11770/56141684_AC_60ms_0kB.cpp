#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=1e4+1;

bool vis[N];

vector<int> adj[N],topo;
void dfs(int v)
{
    vis[v]=true;
    for(int u:adj[v])if(!vis[u])dfs(u);
    topo.push_back(v);
}
void dfs2(int v)
{
    vis[v]=true;
    for(int u:adj[v])if(!vis[u])dfs2(u);
}
int p=0;
void $olve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int ans=0;
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
    memset(vis,0,sizeof(vis));
    reverse(topo.begin(),topo.end());
    for(auto i:topo)if(!vis[i])dfs2(i),ans++;
    cout<<"Case " <<++p<<": ";
    cout<<ans<<enl;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)adj[i].clear();
    topo.clear();
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
    cin>>T;
    while(T--)$olve();
    return 0;
}