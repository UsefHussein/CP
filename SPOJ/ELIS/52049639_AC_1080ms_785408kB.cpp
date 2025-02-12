#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e4+2;
ll dp[N][N];
int n;
vector<ll>a;
ll Dp(ll i,ll prev)
{
    if(i==n)return 0;
    ll &ret=dp[i][prev];
    if(~ret)return ret;
    ret=Dp(i+1,prev);
    if(a[i]>prev)ret=max(ret,Dp(i+1,a[i])+1);
    return ret;
}
void Suii()
{
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ::memset(dp,-1,sizeof dp);
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