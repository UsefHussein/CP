#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int)s.size()


const int N=1e4+1;
vector <pair<int,int>> adj[N];
ll dis[N],n;
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
    for(int i=1;i<=n;i++)dis[i]=1e18;
    dis[start]=0;
    while(!pq.empty())
    {
        node p=pq.top();
        pq.pop();
        if(p.w>dis[p.v])continue;
        if(p.v==en)break;
        for(auto [u,cost]:adj[p.v])
        {
            if(dis[u]>dis[p.v]+cost)
            {
                dis[u]=dis[p.v]+cost;
                pq.push({dis[u],u});
            }
        }
    }
    cout<<dis[en]<<enl;
}

void $olve()
{
    cin>>n;
    map<string,int> mp;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        mp[s]=i;
        int t;
        cin>>t;
        while(t--)
        {
            int v,w;
            cin>>v>>w;
            adj[i].push_back({v,w});
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        string s,m;
        cin>>s>>m;
        dijkstra(mp[s],mp[m]);
    }
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
    int T = 1;
    cin>>T;
    while(T--)$olve();
    return 0;
}