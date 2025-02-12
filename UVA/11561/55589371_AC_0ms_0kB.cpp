#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int) (s).size()

const int N=51;

const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};

char a[N][N];

bool vis[N][N];

int n,m,ans;

bool check(int i, int j)
{
    return i>=0 && j>=0 && i<n && j<m&&a[i][j]!='#';
}

void dfs(int i,int j)
{
    vis[i][j]=true;
    for(int k=0;k<4;k++)
    {
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(check(nx,ny)&&a[nx][ny]=='T')return;
    }
    for(int k=0;k<4;k++)
    {
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(check(nx,ny)&&!vis[nx][ny])
        {
            if(a[nx][ny]=='G')ans++;
            dfs(nx,ny);
        }
    }
}

void $olve()
{
    while(cin>>n>>m)
    {
        swap(n,m);
        int px=0,py=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='P')
                {
                    //cout<<i<< " " << j<<endl;
                    px=i;
                    py=j;
                }
            }
        dfs(px,py);
        cout<<ans<<endl;
        ans=0;
        memset(vis,0,sizeof(vis));
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