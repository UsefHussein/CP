#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int)s.size()


const int N=1e3;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int n,m;
ll a[N][N],dis[N][N];
struct node
{
    ll cost;
    int x,y;
    bool operator<(const node& other) const
    {
        return  cost > other.cost;
        // Reverse logic for min-heap
    }
};
bool valid(int i,int j)
{
    return i>=0 && i<n && j>=0 && j<m;
}
void dijkstra()
{
    priority_queue<node> q;
    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)dis[i][j]=1e18;
    q.push({0,0,0});
    dis[0][0]=0;
    while(!q.empty())
    {
        node p=q.top();
        q.pop();
        if(p.cost>dis[p.x][p.y])continue;
        for(int i=0;i<4;i++)
        {
            int nx=p.x+dx[i];
            int ny=p.y+dy[i];
            if(valid(nx,ny)&&
                dis[nx][ny]>dis[p.x][p.y]+a[p.x][p.y])
            {
                dis[nx][ny]=dis[p.x][p.y]+a[p.x][p.y];
                q.push({p.cost+a[p.x][p.y],nx,ny});
            }
        }
    }
    cout<<dis[n-1][m-1]+a[n-1][m-1]<<enl;
}
void $olve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    dijkstra();
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