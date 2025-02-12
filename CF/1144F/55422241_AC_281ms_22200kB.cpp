#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) x.size()

const int N=2e5+1;

vector<int>adj[N],topo;

bool vis[N];

int bip[N];

bool bo=1;
void dfs(int x,int p)
{
    vis[x]=1;
    bip[x]=p;
    for(int y:adj[x])
    {
        if(!vis[y])
        {
            dfs(y,p^1);
        }
    }
}

void $olve()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>a(m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        a[i]={ u,v};
    }
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0);
    for(int i=0;i<m;i++)if(bip[a[i].F]==bip[a[i].S])return void(cout<<"NO");
    cout<<"YES"<<enl;
    for(int i=0;i<m;i++)
    {
        if(bip[a[i].F]==1)cout<<"1";
        else cout<<"0";
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