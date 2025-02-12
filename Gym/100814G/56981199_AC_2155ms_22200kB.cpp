#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int)s.size()

const int N=1e5+1;
struct p
{
    ll u,cost,wes;
};
vector<p>adj[N];
ll dis[N],n,m,lmt;
struct node
{
    ll cost,v;
    bool operator<(const node& other) const
    {
        return  cost > other.cost;
        // Reverse logic for min-heap
    }
};
bool dijkstra(int mid)
{
    priority_queue<node>pq;
    pq.push({0,1});
    for(int i=0;i<=n;i++)dis[i]=1e18;
    dis[1]=0;
    while(!pq.empty())
    {
        node p=pq.top();
        pq.pop();
        if(p.cost>dis[p.v])continue;
        for(auto [u,cost,w]:adj[p.v])
        {
            if(dis[u]>dis[p.v]+cost&&w<=mid)
            {
                dis[u]=dis[p.v]+cost;
                pq.push({dis[u],u});
            }
        }
    }
    int bo=1;
    if(dis[n]>=lmt)bo=0;
    return bo;
}
void $olve()
{
    cin>>n>>m>>lmt;
    for(int i=0;i<m;i++)
    {
        int u,v,co,ww;
        cin>>u>>v>>co>>ww;
        adj[u].push_back({v,co,ww});
        adj[v].push_back({u,co,ww});
    }
    int l=0,r=1e9,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(dijkstra(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)adj[i].clear();
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
    int T=1;
    cin>>T;
    while(T--)$olve();
    return 0;
}
