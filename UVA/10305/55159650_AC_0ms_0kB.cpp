#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
const int N=1e5+1,Mod=1e9+7;
int n,m;
bool vis[N];
vector<int>adj[N];
vector<int>ans;
void DFS(int node)
{
    vis[node]=1;
    for(auto i:adj[node])
    {
        if(!vis[i])
            DFS(i);
    }
    ans.push_back(node);
}
void $olve()
{
    while(cin>>n>>m)
    {
        if(!n)return;
        memset(vis,0,sizeof(vis));
        ans.clear();
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])DFS(i);
        }
        reverse(all(ans));
        cout<<ans[0];
        for(int i=1;i<n;i++)cout<<" "<<ans[i];
        for(int i=1;i<=n;i++)adj[i].clear();
        cout<<enl;
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