#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
const int N=21,Mod=1e9+7;
ll dp[N+2][(1<<N)+2];
int n;
ll a[N][N];
ll Dp(int i,int mask)
{
    if(i==n)return __popcount(mask)==n;
    ll &ret =dp[i][mask];
    if(~ret)return ret;
    ret=0;
    for(int j=0;j<n;j++)
    {
        if(mask&(1<<j))continue;
        if(a[i][j])ret+=Dp(i+1,mask|(1<<j));
        if(ret>=Mod)ret-=Mod;
    }
    return ret;
}
void $olve()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    memset(dp,-1,sizeof(dp));
    cout<<Dp(0,0);
}
void F_F()
{
    std::ios_base::sync_with_stdio();
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