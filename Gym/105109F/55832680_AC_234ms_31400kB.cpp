#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int Mod=1e9+7,N=1e3+1;
ll dp[N][N];
ll a[N][N],col[N][N],row[N][N];
ll n,m;
ll Dp(int i,int j)
{
    if(i<0 || j<0 )return 1e18;
    if(!i&&!j)return 0;
    ll &ret=dp[i][j];
    if(~ret) return ret;
    ret=1e18;
    if(j>1)ret=min(ret,Dp(i,j-1)+col[i][j-2]*col[i][j-2]);
    else ret=min(ret,Dp(i,j-1));
    if(i>1)ret=min(ret,Dp(i-1,j)+row[i-2][j]*row[i-2][j]);
    else ret=min(ret,Dp(i-1,j));
    return ret;
}
void $olve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            col[i][j]=a[i][j];
            row[i][j]=a[i][j];
        }

    for(int i=0;i<n;i++)
        for(int j=1;j<m;j++)
        {
            col[i][j]+=col[i][j-1];
        }
    for(int i=1;i<n;i++)
        for(int j=0;j<m;j++)
        {
            row[i][j]+=row[i-1][j];
        }
    memset(dp,-1,sizeof(dp));
    cout<<Dp(n-1,m-1)<<enl;
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