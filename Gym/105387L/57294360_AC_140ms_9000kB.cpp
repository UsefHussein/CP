#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
const int N=1e3+5;
const int dx[]={0,-1,-1,0,1,1};
const int dy[2][6]={{-1,0,-1,1,-1,0},{-1,0,1,1,1,0}};
ll dis[N][N],n,m,ans=1e18;
char a[N][N];
struct node
{
    ll w;
    int x,y;
    bool operator<(const node& other) const
    {
        return  w > other.w;
        // Reverse logic for min-heap
    }
};
bool valid(int i,int j)
{
    return (i>=0&&i<n&&j>=0&&j<m);
}

void dijkstra()
{
    priority_queue<node>pq;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dis[i][j]=1e18;

    for(int i=0;i<m;i++)
    {
        dis[0][i]=a[0][i]=='.';
        pq.push({dis[0][i],0,i});
    }
    while(!pq.empty())
    {
        node p=pq.top();
        pq.pop();
        if(p.w>dis[p.x][p.y])continue;
        for(int k=0;k<6;k++)
        {
            int nx=p.x+dx[k];
            int ny=p.y+dy[p.x%2][k];
            if(valid(nx,ny))
            {
                if(dis[nx][ny]>dis[p.x][p.y]+(a[nx][ny]=='.'))
                {
                    dis[nx][ny]=dis[p.x][p.y]+(a[nx][ny]=='.');
                    pq.push({ dis[nx][ny],nx,ny});
                }
            }
        }
    }
    for(int i=0;i<m;i++)ans=min(ans,dis[n-1][i]);
}
void $olve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    dijkstra();
    cout<<ans<<enl;
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
    int T = 1;//cin>>T;
    while(T--)$olve();
    return 0;
}
