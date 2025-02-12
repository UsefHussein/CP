#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
// 1ll<<i متنساش ll
const int N=1e5+2;
ll n,c,dp[102][N],a[N][2];
ll Dp(int i,ll j)
{
    if(i==n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll op1=Dp(i+1,j);
    ll op2=0;
    if(j+a[i][0]<=c)op2=Dp(i+1,j+a[i][0])+a[i][1];
    return dp[i][j]=max(op2,op1);
}
void Suii()
{
    cin>>n>>c;
    for(int i=0;i<n;i++)for(int j=0;j<2;j++)cin>>a[i][j];
    memset(dp,-1,sizeof dp);
    cout<<Dp(0,0);
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