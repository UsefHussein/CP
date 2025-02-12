#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
const int N=1e5+1,Mod=1e9+7;
const int dx[]={-2,-1,-1,-2,1  ,2 ,1 ,2};
const int dy[]={1,2,  -2,-1,-2 ,1 ,2 ,-1};
int n,m,ans;
bool vis[N];
vector<int> adj[N];
vector<int>topo;
void DFS(int node)
{
    vis[node]=1;
    for(auto ch:adj[node])
    {
        if(!vis[ch]) DFS(ch);
    }
    topo.push_back(node);
}
void $olve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int w;cin>>w;
        while(w--)
        {
            int v;
            cin>>v;
            adj[i].push_back(v);
        }
    }
    for(int i=1;i<=n;i++)if(!vis[i])DFS(i);
    vector<int> ans(n+1);
    for(int i=0;i<sz(topo)-1;i++) {
        ans[topo[i]]=topo[i+1];
    }
    ans[topo.back()]=0;
    for(int i=1;i<=n;i++)cout<<ans[i]<<enl;
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