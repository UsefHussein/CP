#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int)s.size()


const int N=1e3+1;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int n,m;
ll a[N][N];
bool vis[N][N];
struct node {
    int x,y;
    ll cost;
};
int stx,sty,enx,eny;
bool valid(int i,int j)
{
    return i>=0 && i<n && j>=0 && j<m&&!a[i][j]&&!vis[i][j];
}
void bfs()
{
    queue<node> q;
    q.push({stx,sty,0});
    while(!q.empty())
    {
        node p=q.front();
        q.pop();
        if(p.x==enx && p.y==eny)
        {
            cout<<p.cost<<enl;
            return;
        }
        for(int i=0;i<4;i++)
        {
            int nx=p.x+dx[i];
            int ny=p.y+dy[i];
            if(valid(nx,ny))
            {
                vis[nx][ny]=true;
                q.push({nx,ny,p.cost+1});
            }
        }
    }
cout<<"-1\n";
}
void $olve()
{
    while(cin>>n>>m)
    {
        if(!n && !m)return;
        int q;
        cin>>q;
        while(q--)
        {
            int u,t;
            cin>>u>>t;
            for(int i=0;i<t;i++)
            {
                int v;
                cin>>v;
                a[u][v]=1;
            }
        }
        cin>>stx>>sty>>enx>>eny;
        bfs();
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
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