#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
const int N=101,Mod=1e9+7;
const int dx[]={0,0,1,-1};
const int dy[]={-1,1,0,0};
int n,m,id;
bool vis[N][N];
char a[N][N];
bool valid(int i,int j)
{
    return i>=0&&i<n&&j>=0&&j<m&&!vis[i][j]&&(a[i][j]=='x'||a[i][j]=='@');
}
void DFS(int i,int j)
{
    vis[i][j]=true;
    for(int k=0;k<4;k++)
    {
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(valid(nx,ny))
        {
            DFS(nx,ny);
        }
    
    }
}
void $olve()
{
	cin>>n;
    m=n;
	memset(vis,0,sizeof vis);
    ll ans=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(a[i][j]=='x'&&!vis[i][j]){DFS(i,j);ans++;}
    //Case 1: 2
    cout<<"Case "<<++id<<": "<<ans<<enl;
}
void F_F()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

}
signed main()
{
    F_F();
    int T = 1;
    cin>>T;
    while(T--)$olve();
    return 0;
}