#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
const int N=1e4+1,Mod=1e9+7;
int n,m,mx,root;
bool vis[N];
int dis[N];
vector<int> adj[N];
void DFS(int node,int cost)
{
    vis[node]=1;
    if(cost>mx)
    {
        mx=cost;
        root=node;
    }
    for(auto ch:adj[node])
    {
        if(!vis[ch])
        {
            dis[ch]=dis[node]+1;
            DFS(ch,cost+1);
        }
    }
}
void $olve()
{
    cin>>n;
    if(n<=1)return void(cout<<0);
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1,0);
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    mx=0;
    DFS(root,0);
    cout<<mx;
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