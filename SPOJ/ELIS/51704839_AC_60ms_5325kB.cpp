#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
// 1ll<<i متنساش ll
const int N=1e5+5;
ll n,dp[50][250];
vector<ll>a;
ll Dp(int i,int j)
{
    if(i==n)return 0;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    ret=Dp(i+1,j);
    if(a[i]>j)ret=max(Dp(i+1,a[i])+1,ret);
    return ret;
}
void Suii()
{
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    memset(dp,-1, sizeof dp);
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