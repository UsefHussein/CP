#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define S second
#define F first
#define all(x) x.begin(), x.end()
#define sz(x) x.size()

const int N=1e5+1;

vector<int>adj[N];

bool vis[N];

int mark[N],n;

void dfs(int node,int type=0)
{
    vis[node]=1;
    mark[node]=type;
    for(auto i:adj[node])
    {
        if(!vis[i])
        {
            dfs(i,type^1);
        }
    }
}


void $olve()
{
    cin>>n;
    int root=0;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        if(!root)root=u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(root);
    ll cnt0=0,cnt1=0;
    ll cnt2=0,cnt3=0;
    for(int i=1;i<=n;i++)mark[i]?cnt1++:cnt0++;
    for(int i=1;i<=n;i++)
    {
        if(mark[i]==1) {
            cnt2+=cnt0-sz(adj[i]);
        }
        else cnt3+=cnt1-sz(adj[i]);
    }
    cout<<min(cnt2,cnt3)<<enl;
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