#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int)s.size()
ll GetBit(ll n,int i)
{
    return (n>>i)&1ll;
}
ll SetBit1(ll n,int i)
{
    return (n|(1ll<<i));
}
const int N=101;
int n,m;
ll dist[N][N];
const ll inf = 1e18;
vector<int> adj[N];
vector<pair<int,int>> edge;
ll dp[N][1<<13];
int st;
ll Dp(int i=st,int mask=0)
{
    if(__builtin_popcount(mask)==sz(edge))return dist[i][st];
    ll &ret = dp[i][mask];
    if(~ret)return ret;
    ret=1e18;
    for(auto e:adj[i])
    {
        for(int j=0;j<sz(edge);j++)
        {
            if(GetBit(mask,j))continue;
            if(i==edge[j].first&&e==edge[j].second)
            {
                ret=min(ret,Dp(e,SetBit1(mask,j))+dist[i][e]);
            }
        }
    }
    for(int j=1;j<=n;j++)
    {
        if(i==j)continue;

        ret=min(ret,Dp(j,mask)+dist[i][j]);
    }
    return ret;
}
void $olve()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>st;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            dist[i][j] = inf;
            dist[i][i] =0;
        }
    }
    for (int i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        dist[u][v]  =min(dist[u][v],w);
        dist[v][u] = min(dist[v][u],w);
    }
    for (int node = 1;node<=n;node++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j = 1;j<=n;j++)
            {
                if (dist[i][node] < inf&&dist[node][j]<inf)
                {
                    dist[i][j]=min(dist[i][j],dist[i][node]+dist[node][j]);
                }
            }
        }
    }
    int q;cin>>q;
    while (q--)
    {
        int u,v,t;
        cin>>u>>v>>t;
        adj[u].push_back(v);
        while (t--)
        {
            edge.push_back({u,v});
        }
    }
    cout<<Dp()<<enl;
    for (int i=1;i<=n+5;i++)adj[i].clear();
    edge.clear();
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
    int T = 1;
    cin>>T;
    while(T--)$olve();
    return 0;
}