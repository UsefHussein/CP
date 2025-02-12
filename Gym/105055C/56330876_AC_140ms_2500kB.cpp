#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(s) int(s.size())

const int N=1e5+5;
bool vis[N];
vector<int> adj[N];
int n;
void bfs()
{
    vector<pair<int,int>> dist(n+5,{1e6,1e6});
    queue<int> q;
    q.push(1);
    dist[1]={vis[1],0};
    while(!q.empty())
    {
        int p=q.front();
        auto it=dist[p];
        q.pop();
        for(auto i:adj[p])
        {
            if(dist[i].F>it.F+vis[i])
            {
                dist[i]={it.F+vis[i],it.S+1};
                q.push(i);
            }
            else if(dist[i].F==it.F+vis[i]&&dist[i].S>it.S+1)
            {
                dist[i]={it.F+vis[i],it.S+1};
                q.push(i);
            }
        }
    }
    cout<<dist[n].F<<" "<<dist[n].S<<enl;
}
void $olve()
{
    int m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {
        int u;
        cin>>u;
        vis[u]=true;
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
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