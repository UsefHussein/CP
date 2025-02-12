#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=102;
ll a[N][2],dp[N][100005],n,w;
ll Dp(int i,ll sum)
{
    if(i==n)
    {
        if(!sum)return 0;
        return 1e9;
    }
    ll &ret=dp[i][sum];
    if(~ret)return ret;
    ret=1e9;
    ret= Dp(i+1,sum);
    ret=min(ret, Dp(i+1,sum-a[i][1])+a[i][0]);
    return ret;
}
void Suii()
{
    cin>>n>>w;
    ll SUM=0;
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < 2; j++)cin >> a[i][j];
        SUM+=a[i][1];
    }
    ::memset(dp,-1,sizeof dp);
    for(int i=SUM;i>=0;i--)
    {
        if(Dp(0,i)<=w)return void(cout<<i<<enl);
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
int32_t main()
{
    F_F();
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}