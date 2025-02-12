#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=1e5+2;
vector<int>adj[N];
int ans=-1;
bool vis[N];
int dfs(int v)
{
    vis[v]=true;
    int cnt=1;
    for(int u:adj[v])
    {
        if(!vis[u])
            cnt^=dfs(u);
    }
    ans+=!cnt;
    return cnt;
}
void $olve()
{
    int n;
    cin>>n;

    if(n&1)
        return void(cout<<"-1"<<enl);

    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout<<ans<<enl;
}
void F_F()
{
    cin.tie(0)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

signed main()
{
    F_F();
    int T = 1;//cin>>T;
    while(T--)$olve();
    return 0;
}