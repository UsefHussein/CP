#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int)s.size()


const int N=1e3+5;
const int dx[]={-1,-1,0,1,1,1,0,-1};
const int dy[]={0,1,1,1,0,-1,-1,-1};
int n,m;
ll dis[N][N];
char a[N][N];
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
    return i>=1 && i<=n && j>=1 && j<=m;
}
int str,stl,er,el;
void dijkstra()
{
    priority_queue<node> q;
    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)dis[i][j]=1e18;
    q.push({0,stl,str});
    dis[stl][str]=0;
    while(!q.empty())
    {
        node p=q.top();
        q.pop();
        if(p.x==el&&p.y==er)
        {
            cout<<p.cost<<enl;
            return;
        }
        if(p.cost>dis[p.x][p.y])continue;
        int nxx=p.x+dx[a[p.x][p.y]-'0'];
        int nyy=p.y+dy[a[p.x][p.y]-'0'];
        if(valid(nxx,nyy)&&dis[nxx][nyy]>dis[p.x][p.y])
        {
            dis[nxx][nyy]=dis[p.x][p.y];
            q.push({dis[nxx][nyy],nxx,nyy});
        }
        for(int i=0;i<8;i++)
        {
            int nx=p.x+dx[i];
            int ny=p.y+dy[i];
            if(valid(nx,ny)&&
                dis[nx][ny]>dis[p.x][p.y]+1)
            {
                dis[nx][ny]=dis[p.x][p.y]+1;
                q.push({dis[nx][ny],nx,ny});
            }
        }
    }
}
void $olve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];

    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>stl>>str>>el>>er;
        dijkstra();
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