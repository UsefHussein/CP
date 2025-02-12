#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define ld long double
#define sz(s) (int)s.size()

const int N=110;
vector<pair<int,ld>>adj[N];
int l,u,n;
ld dis[N];
struct rec
{
    int h,w,d,k;
    bool operator<(const rec& other) const
    {
        return  d < other.d;
        // Reverse logic for min-heap
    }
};
struct node
{
    ld w;int v;
    bool operator<(const node& other) const
    {
        return  w > other.w;
    }
};
void dijkstra()
{
    priority_queue<node>pq;
    pq.push({0,0});
    for(int i=0;i<=n+2;i++)dis[i]=1e18;
    dis[0]=0;
    while(!pq.empty())
    {
        node p=pq.top();
        pq.pop();
        if(p.w>dis[p.v])continue;
        for(auto [u,cost]:adj[p.v])
        {
            if(dis[u]>dis[p.v]+cost)
            {
                dis[u]=dis[p.v]+cost;
                pq.push({dis[u],u});
            }
        }
    }
    cout<<fixed<<setprecision(6)<<dis[n+1]<<enl;
}
vector<rec>a;

void $olve()
{
    cin>>n>>l>>u;
    a.resize(n+5);
    for(int i=1;i<=n;i++)cin>>a[i].h>>a[i].w>>a[i].d>>a[i].k;
    sort(a.begin()+1,a.begin()+n+1);
    auto dd = [&](int i , int j)->ld
    {
        if (a[i].k == a[j].k)return a[j].d - a[i].d - a[i].h ;
        if (u < a[i].w + a[j].w) return a[j].d - a[i].d - a[i].h ;
        if (a[i].d + a[i].h >= a[j].d) return u - a[i].w - a[j].w ;
        long double f = a[j].d - a[i].d - a[i].h ;
        long double s = u- a[i].w - a[j].w;
        return sqrt(f*f + s*s) ;
    };
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
           adj[i].push_back({j,dd(i,j)});
           adj[j].push_back({i,dd(i,j)});
        }
    }
    for(int i=1;i<=n;i++)
    {
        adj[0].push_back({i,a[i].d});
        adj[i].push_back({n+1,l-(a[i].d+a[i].h)});
    }
    adj[0].push_back({n+1,l});
    dijkstra();
    for(int i=0;i<=n+1;i++)adj[i].clear();
}
void F_F()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("street.in", "r", stdin);
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