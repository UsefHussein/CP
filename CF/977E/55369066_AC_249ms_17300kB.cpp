#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(x) x.size()

const int N=2e5+1;

vector<int>adj[N];

bool vis[N];

bool bo=1;

void dfs(int v)
{
    vis[v]=true;
    if(sz(adj[v])!=2)bo=0;
    for(auto x:adj[v])
    {
        if(!vis[x])dfs(x);
    }
}

void $olve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            if(bo)ans++;
            bo=1;
        }
    }
    cout<<ans;
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