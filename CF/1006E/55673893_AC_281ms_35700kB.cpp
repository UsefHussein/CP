#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=2e5+1;

bool vis[N];

vector<int> adj[N],v,sz,be;

void dfs(int u)
{
    vis[u]=1;
    for(int c:adj[u])
    {
        if(!vis[c])
        {
            v.emplace_back(c);
            dfs(c);
        }
    }

    for(auto c:adj[u])sz[u]+=sz[c];
    sz[u]++;
}
void $olve()
{
    int n,q;
    cin>>n>>q;
    sz.resize(n+2);
    be.resize(n+2);
    for(int i=2;i<=n;i++)
    {
        int u,v=i;
        cin>>u;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    v.emplace_back(1);
    dfs(1);
    for(int i=1;i<=n;i++)be[v[i-1]]=i-1;
    while(q--)
    {
        int node,id;
        cin>>node>>id;
        if(sz[node]<id)
        {
            cout<<-1<<enl;
            continue;
        }
        int i=be[node]+id-1;
        cout<<v[i]<<enl;
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