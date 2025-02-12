#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e5+2;
vector<ll>a,b;
int n,w;
ll dp[102][N];
ll Dp(int i=0,int W=0)
{
    if(i==n)return 0;
    ll &ret=dp[i][W];
    if(~ret)return ret;
    ret=max(Dp(i+1,W),ret);
    if(a[i]+W<=w)ret=max(Dp(i+1,W+a[i])+b[i],ret);
    return ret;
}
void $olve()
{
    cin>>n>>w;
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
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