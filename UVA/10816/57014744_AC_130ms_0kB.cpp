#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define ld long double
#define sz(s) (int)s.size()

struct dis
{
    int u;
    ld temp,km;
};
const int N=101;
vector<dis>adj[N];
ld dis[N];
int par[N];
int st,en,n,m;
vector<int>ans,v;
struct node
{
    ld cost;
    ll v;
    bool operator<(const node& other) const
    {
        return  cost > other.cost;
        // Reverse logic for min-heap
    }
};
ld dijkstra(ld mid)
{
    priority_queue<node>pq;
    pq.push({0,st});
    for(int i=0;i<=n;i++)dis[i]=1e18,par[i]=-1;
    dis[st]=0;
    while(!pq.empty())
    {
        node p=pq.top();
        pq.pop();
        if(p.cost>dis[p.v])continue;
        for(auto [u,cost,w]:adj[p.v])
        {
            if(dis[u]>dis[p.v]+w&&cost<=mid)
            {
                dis[u]=dis[p.v]+w;
                par[u]=p.v;
                pq.push({dis[u],u});
            }
        }
    }
    ld ans=dis[en];
    if(ans==1e18)return -1.0;
    v=vector<int>();
    int p=en;
    while(1)
    {
        v.push_back(p);
        p=par[p];
        if(!~par[p])
        {
            v.push_back(p);
            break;
        }
    }
    reverse(v.begin(),v.end());
    return ans;
}
void $olve()
{
    while(cin>>n>>m>>st>>en)
    {
        while(m--)
        {
            int u,v;
            ld te,k;
            cin>>u>>v>>te>>k;
            adj[u].push_back({v,te,k});
            adj[v].push_back({u,te,k});
        }
        ld anstemp=-1,anskm=-1,l=0,r=55,mid;
        for(int i=0;i<=300;i++)
        {
            mid=(l+r)/2.0;
            ld op=dijkstra(mid);
            if(op!=-1.0)
            {
                anstemp=mid;
                anskm=op;
                ans=v;
                r=mid;
            }
            else l=mid;
        }
        cout<<ans.front();
        ans.erase(ans.begin());
        for(auto it:ans)cout<<" "<<it;
        cout<<enl;
        cout<<fixed<<setprecision(1)<<anskm<<" "<<anstemp<<enl;
        ans.clear();
        for(int i=0;i<=n;i++)adj[i].clear();
    }
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