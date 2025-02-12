#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
const int N=101,Mod=1e9+7;
ll dp[N][1<<15];
int n,m;
int a[N][N];
int id;
ll Flip(ll n,int i)
{
    return (n ^ (1 << i));
}
ll Dp(int i,int mask) {
    if(i==m)return !mask?0:1e18;
    ll &ret=dp[i][mask];
    if(~ret)return ret;
    ret=1e18;
    ret=min(ret,Dp(i+1,mask));
    int New=mask;
    for(int j=0;j<n;j++)
    {
        if(a[i][j])New=Flip(New,j);
    }
    ret=min(ret,Dp(i+1,New)+1);
    return ret;
}
void $olve()
{
    id++;
    cin>>n>>m;
    for(int i=0;i<m;i++)for(int j=0;j<n;j++)cin>>a[i][j];
    memset(dp,-1,sizeof(dp));
    int p=0;
    for(int j=0;j<n;j++)p=Flip(p,j);
    ll ans=Dp(0,p),k=1e18;
    cout<<"Case "<<id<<": ";
    if(ans==k)cout<<"IMPOSSIBLE"<<enl;
    else cout<<ans<<enl;
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