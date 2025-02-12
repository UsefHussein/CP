#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=5e3+1;

bool vis[N],bo=0,vis2[N];

vector<int> adj[N];

int tar,cnt=0;

void dfs(int u)
{
    vis[u]=1;
    if(u==tar)bo=1;
    for(int c:adj[u])
    {
        if(!vis[c])dfs(c);
    }
}
void dfs2(int u)
{
    vis2[u]=1;
    cnt++;
    for(int c:adj[u])
    {
        if(!vis2[c])dfs2(c);
    }
}
void $olve()
{
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
    }
    ll ans=0;
    vector<pair<int,int>>o;
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        memset(vis2,0,sizeof(vis2));
        tar=i;
        dfs(s);
        if(!bo)
        {
            dfs2(i);
            o.emplace_back(cnt,i);
        }
        bo=0;
        cnt=0;
    }
    sort(o.rbegin(),o.rend());
    for(auto i:o)
    {
        memset(vis,0,sizeof(vis));
        tar=i.second;
        dfs(s);
        if(!bo)
        {
            adj[s].emplace_back(i.second);
            ans++;
        }
        bo=0;
        cnt=0;
    }
    cout<<ans<<enl;
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