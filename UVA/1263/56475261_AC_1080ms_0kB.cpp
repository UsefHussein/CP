#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int) (s).size()


const int N=2e3+1;
const int dx[]={-1,1,-1,1};
const int dy[]={1,-1,-1,1};
struct node
{
    int x,y,d;
};
vector<int> adj[N],topo;
bool vis[N];
void dfs(int p)
{
    vis[p]=1;
    for(auto i:adj[p])if(!vis[i])dfs(i);
    topo.push_back(p);
}
void $olve()
{
    int n;
    cin>>n;
    vector<node> a(n);
    for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y>>a[i].d;
    for(int i=0;i<n;i++)
    {
        int lx=a[i].x-(a[i].d/2);
        int rx=a[i].x+(a[i].d/2);
        int ly=a[i].y-(a[i].d/2);
        int ry=a[i].y+(a[i].d/2);
        for(int j=0;j<n;j++)
        {
            if(i==j)continue;
            if(lx<=a[j].x&&rx>=a[j].x&&ly<=a[j].y&&ry>=a[j].y)
            {
                adj[i+1].push_back(j+1);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])dfs(i);
    }
    memset(vis,0,sizeof(vis));
    reverse(topo.begin(),topo.end());
    int sz=sz(topo),ans=0;
    for(int i=0;i<sz;i++)
    {
        if(!vis[topo[i]])dfs(topo[i]),ans++;
    }
    cout<<ans<<enl;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++)adj[i].clear();
    topo.clear();
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