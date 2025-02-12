#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int) (s).size()
#define S second
#define F first

const int N = 1e4+1;

bool vis[N];

int mx,root=-1;

vector<pair<int,int>>adj[N];

void dfs(int u,ll cost)
{
    vis[u] = true;
    if(cost>mx)
    {
        mx = cost;
        root = u;
    }
    for(auto [i,j]:adj[u])
    {
        if(!vis[i])dfs(i,cost+j);
    }
}
void $olve()
{
    string s;
    while(getline(cin,s))
    {
        if(s.empty())
        {
            dfs(root,0);
            mx=0;
            memset(vis,false,sizeof(vis));
            dfs(root,0);
            cout<<mx<<enl;
            mx=0;root=-1;
            memset(vis,false,sizeof(vis));
            for(int i=0;i<N;i++)adj[i].clear();
        }
        else
        {
            istringstream ss(s);
            int u,v,cost;
            ss >> u >> v >> cost;
            if(root==-1)root=u;
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }
    }
    dfs(root,0);
    mx=0;
    memset(vis,false,sizeof(vis));
    dfs(root,0);
    cout<<mx<<enl;
    mx=0;root=-1;
    memset(vis,false,sizeof(vis));
    for(int i=0;i<N;i++)adj[i].clear();
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