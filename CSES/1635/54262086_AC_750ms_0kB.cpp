#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e6+2,Mod=1e9+7;
vector<ll>a;
int n,w;
ll dp[N];
ll Dp(int W=0)
{
    if(W>w)return 0;
    if(w==W)return 1;
    ll &ret=dp[W];
    if(~ret)return ret%Mod;
    ret=0;
    for(auto j:a)ret+=(Dp(W+j))%Mod;
    return ret%Mod;
}
void $olve()
{
    cin>>n>>w;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ::memset(dp,-1,sizeof dp);
    cout<<Dp();
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