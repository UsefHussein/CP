#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e5+5;
ll n;
vector<vector<ll>>dp;
vector<ll>a,h;
ll Dp(ll i,ll j)
{
    if(i>=n-1)return 0;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    // 0 its left
    // 2 its right
    ret=Dp(i+1,1);
    if(j<=1)
    {
        if(a[i]-h[i]>a[i-1])
            ret=max(ret,Dp(i+1,0)+1);
    }
    if(j==2)
    {
        if(a[i]-h[i]>a[i-1]+h[i-1])
            ret=max(ret,Dp(i+1,0)+1);
    }
    if(a[i]+h[i]<a[i+1])ret=max(ret,Dp(i+1,2)+1);
    return ret;
}
void Suii()
{
    cin>>n;
    a.resize(n);
    h.resize(n);
    for(int i=0;i<n;i++)cin>>a[i]>>h[i];
    dp.assign(N,vector<ll>(3,-1));
    if(n==1)cout<<Dp(1,0)+1<<enl;
    else cout<<Dp(1,0)+2<<enl;
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