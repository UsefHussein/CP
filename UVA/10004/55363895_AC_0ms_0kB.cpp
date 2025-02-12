#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define enl '\n'
#define ll long long

const int N=201;

bool vis[N];

int mark[N];

int n;

vector<int>adj[N];

void dfs(int node,int type)
{
    vis[node]=true;
    mark[node]=type;
    for(auto i:adj[node])
    {
        if(!vis[i])dfs(i,type^1);
    }
}

void $olve()
{
    while(cin>>n)
    {
        if(!n) return;
        int m;cin>>m;
        int root=-1;
        for(int i=0;i<m;i++)
        {
            int u,v;cin>>u>>v;
            if(root==-1)root=u;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(root,0);
        bool bo=1;
        for(int i=0;i<n;i++)
        {
            for(auto j:adj[i])
            {
                if(mark[j]==mark[i])bo=0;
            }
        }
        for(int i=0;i<n;i++)adj[i].clear();
        memset(vis, 0, sizeof vis);
        cout<<(bo?"BICOLORABLE.":"NOT BICOLORABLE.")<<enl;
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