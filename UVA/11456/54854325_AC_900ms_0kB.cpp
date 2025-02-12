#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
const int N=2001,Mod=1e9+7;
ll dp[N][N];
ll dp2[N][N];
vector<ll>a;
int n;
ll Dp(int i,int mn)
{
    if(i==n)return 0;
    ll &ret=dp[i][mn];
    if(~ret)return ret;
    ret=Dp(i+1,mn);
    if(a[i]<a[mn])ret=max(ret, Dp(i+1,i)+1);
    return ret;
}
ll Dp2(int i,int mx)
{
    if(i==n)return 0;
    ll &ret=dp2[i][mx];
    if(~ret)return ret;
    ret=Dp2(i+1,mx);
    if(a[i]>a[mx])ret=max(ret, Dp2(i+1,i)+1);
    return ret;
}
void $olve()
{
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ::memset(dp,-1,sizeof dp);
    ::memset(dp2,-1,sizeof dp2);
    ll mx=0;
    for(int i=0;i<n;i++)mx=max(mx,Dp2(i+1,i)+Dp(i+1,i)+1);
    cout<<mx<<enl;;
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
    cin>>T;
    while(T--)$olve();
    return 0;
}