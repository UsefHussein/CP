#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define ll long long

const int N=1e5+5;
int n;
vector<pair<int,int>>adj[N];
ll dis[N][2];
struct node
{
    ll w,v;
    bool bo;
    bool operator<(const node& other) const
    {
        return w > other.w; // Reverse logic for min-heap
    }
};
void dijkstra(int start)
{
    priority_queue<node>pq;
    pq.push({0,start,0});
    for(int i=1;i<=n;i++)dis[i][0]=dis[i][1]=1e18;
    dis[start][0]=0;
    while(!pq.empty())
    {
        node p=pq.top();
        pq.pop();
        if(p.w>dis[p.v][p.bo])continue;
        for(auto [u,cost]:adj[p.v])
        {
            if(dis[u][p.bo]>dis[p.v][p.bo]+cost)
            {
                dis[u][p.bo]=dis[p.v][p.bo]+cost;
                pq.push({dis[u][p.bo],u,p.bo});
            }
            if(!p.bo)
            {
                if(dis[u][1]>dis[p.v][0]+(cost/2))
                {
                    dis[u][1]=dis[p.v][0]+cost/2;
                    pq.push({dis[u][1],u,1});
                }
            }
        }
    }
    cout<<dis[n][1]<<enl;
}
void $olve()
{
    int m;
    cin>>n>>m;
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    dijkstra(1);
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
    //cin>>T;
    while(T--)$olve();
    return 0;
}