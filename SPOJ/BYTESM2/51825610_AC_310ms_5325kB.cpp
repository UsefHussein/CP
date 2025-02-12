#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=102;
ll a[N][N],dp[N][N],n,m;
ll Dp(int i,int j)
{
    if(i>=n)
    {
        return 0;
    }
    ll &ret=dp[i][j];
    if(~ret)return ret;
    ret=Dp(i+1,j)+a[i][j];
    if(j!=0)ret=max(ret,Dp(i+1,j-1)+a[i][j]);
    if(j!=m-1)ret=max(ret,Dp(i+1,j+1)+a[i][j]);
    return ret;
}
void Suii()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
    ll mx=0;
    for(int i=0;i<m;i++)
    {
        ::memset(dp,-1,sizeof dp);
        mx=max(mx,Dp(0,i));
    }
    cout<<mx<<enl;
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
int32_t main()
{
    F_F();
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}