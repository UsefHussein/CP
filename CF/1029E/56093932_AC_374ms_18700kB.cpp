#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=2e5+1;

int dis[N],par[N];
vector<int>adj[N];
int n;



void bfs (int node)
{
    queue<int> q;
    q.push(node);
    dis[node]=0;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(auto child:adj[p])
        {
            if(dis[child]==-1)
            {
                dis[child]=dis[p]+1;
                par[child]=p;
                q.push(child);
            }
        }
    }
}
void $olve()
{
    memset(dis,-1,sizeof(dis));
    memset(par,0,sizeof(par));
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    ll ans=0;
    set<pair<int,int>,greater<pair<int,int>>> st;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]>2)st.insert({dis[i],i});
    }
    while(!st.empty())
    {
        int p=par[st.begin()->second];
        ans++;
        for(auto child:adj[p])
        {
            if(st.find({dis[child],child})!=st.end())
            {
                st.erase(st.lower_bound({dis[child],child}));
            }
        }
        if(st.find({dis[p],p})!=st.end())
            st.erase(st.lower_bound({dis[p],p}));
    }
    cout<<ans<<enl;
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