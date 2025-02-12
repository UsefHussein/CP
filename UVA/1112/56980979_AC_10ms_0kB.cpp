#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int)s.size()

const int N=100;
int n,m;
ll dist[N][N];

const ll inf = 1e18;
int T = 1;
void $olve()
{
    int n,e,t,m;
    cin>>n>>e>>t>>m;
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
        dist[u][v] =min(dist[u][v],w);
    }
    for (int node = 1;node <= n; node++)
    {
        for (int i = 1;i <= n; i++)
        {
            for (int j = 1;j <= n; j++)
            {
                if (dist[i][node] < inf&&dist[node][j]<inf)
                {
                    dist[i][j]=min(dist[i][j],dist[i][node]+dist[node][j]);
                }
            }
        }
    }
    ll ans=0;
    for (int i=1;i<=n;i++)ans+=dist[i][e]<=t;
    cout<<ans<<enl;
    if(T)cout<<"\n";

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

    cin>>T;
    while(T--)$olve();
    return 0;
}
