#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=1e2+1;
ll dp[11][N][N];
ll vis[11][N][N];
int a[11][N];
int n,m,id=1;
ll Dp(int i,int j,int h)
{
    if(h<0)return -1e9;
    if(i==n)return 0;
    if(j>=m)return -1e9;
    ll &ret=dp[i][j][h];
    if(vis[i][j][h]==id) return ret;
    vis[i][j][h]=id;
    ret=-1e9;
    if(a[i][j]>=5)ret=max(ret,Dp(i+1,0,h-(j+1))+a[i][j]);
    ret=max(ret,Dp(i,j+1,h));
    return ret;
}
void $olve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    ll ans=Dp(0,0,m);

    if(ans<=0)cout<<"Peter, you shouldn't have played billiard that much.\n";
    else
    {
        cout<<fixed<<setprecision(2);
        double op=(double)ans/n;
        cout<<"Maximal possible average mark - "<<op+1e-8  <<".\n";
    }
    id++;
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
    memset(dp,-1,sizeof(dp));
    int T = 1;cin>>T;
    while(T--)$olve();
    return 0;
}
