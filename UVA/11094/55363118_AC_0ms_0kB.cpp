#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=21;
const int dx[]={0 ,0,-1,1};
const int dy[]={-1,1,0,0};

bool vis[N][N];

char a[N][N];

int n,m,x,y;

bool valid(int i,int j)
{
    return i>=0&& i<n && j>=0 && j<m&&a[i][j]==a[x][y]&&!vis[i][j];
}


int dfs(int i,int j)
{
    vis[i][j]=true;
    if(x==i && y==j)
    {
        return -1e9;
    }
    int mx=1;
    for(int k=0;k<4;k++)
    {
        int nx=i+dx[k];
        int ny=j+dy[k];
        ny+=m;ny%=m;
        if(valid(nx,ny))
        {
            mx+=dfs(nx,ny);
        }
    }
    return mx;
}

void $olve()
{
    while(cin>>n>>m)
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];

        cin>>x>>y;
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==a[x][y])
                {
                    memset(vis,0,sizeof(vis));
                    int u=dfs(i,j);
                    //cout<<i<< " "<<j<<" "<<u<<enl;
                    if(u>0)ans=max(ans,u);
                }
            }

        cout<<ans<<enl;
    }

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