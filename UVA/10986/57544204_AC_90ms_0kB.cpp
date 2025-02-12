#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int)s.size()


const int N=2e4+1;
vector <pair<int,int>> adj[N];
ll dis[N],n,id=1;
struct node
{
    ll w,v;
    bool operator<(const node& other) const
    {
        return  w > other.w;
        // Reverse logic for min-heap
    }
};
void dijkstra(int start,int en)
{
    priority_queue<node>pq;
    pq.push({0,start});
    for(int i=0;i<=n;i++)dis[i]=1e18;
    dis[start]=0;
    while(!pq.empty())
    {
        node p=pq.top();
        pq.pop();
        if(p.w>dis[p.v])continue;
        if(p.v==en)
        {
            break;
        }
        for(auto [u,cost]:adj[p.v])
        {
            if(dis[u]>dis[p.v]+cost)
            {
                dis[u]=dis[p.v]+cost;
                pq.push({dis[u],u});
            }
        }
    }
    //Case #3: unreachable
    if(dis[en]==1e18)cout<<"Case #"<<id++<<": unreachable"<<endl;
    else cout<<"Case #"<<id++<<": "<<dis[en]<<endl;
}

void $olve()
{
    int m,s,e;
    cin>>n>>m>>s>>e;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    if(s>e)swap(s,e);
    dijkstra(s,e);
    for(int i=0;i<=n;i++)adj[i].clear();
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