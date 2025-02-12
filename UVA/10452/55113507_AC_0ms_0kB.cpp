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
const int N=11,Mod=1e9+7;
const int dx[]={-1,0,0};
const int dy[]={0,-1,1};
int n,m;
bool vis[N][N];
char a[N][N];
int ind;
string Valid="IEHOVA#";
vector<string>ans={"forth","left","right"};
bool valid(int i,int j)
{
    return i>=0&&i<n&&j>=0&&j<m&&!vis[i][j]&&a[i][j]==Valid[ind];
}
void DFS(int i,int j)
{
    vis[i][j]=true;
    for(int k=0;k<3;k++)
    {
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(valid(nx,ny))
        {
            if(ind)cout<<" "<<ans[k];
            else cout<<ans[k];
            ind++;
            if(a[nx][ny]=='#')return;
            DFS(nx,ny);
        }
    
    }
}
void $olve()
{
	cin>>n>>m;
	memset(vis,0,sizeof vis);
    ind=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(a[i][j]=='@'){DFS(i,j);cout<<enl;return;}
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