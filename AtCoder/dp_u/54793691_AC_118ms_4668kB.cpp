#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(x) int(x.size())
#define F first
#define S second
const int N=16,Mod=1e9+7;
ll a[N][N],cost[1<<N];
ll n;
ll dp[1<<N];
void mxsubmasks(int o)
{
    for(int i=0;i<=o;i++)
    {
        vector<int>v;
        ll sum=0;
        ll p=1;
        while(p<i)p<<=1;
        for(int j=0;j<=__popcount(p-1);j++)if((i>>j)&1)v.push_back(j);
        for(int t=0;t<sz(v);t++)for(int y=t+1;y<sz(v);y++)sum+=a[v[t]][v[y]];
        cost[i]=sum;
    }
}
ll Dp(int mask=((1<<n)-1))
{
    if(!mask)return 0;
    ll &ret=dp[mask];
    if(~ret)return ret;
    ret=-1e18;
    for(int i=mask;i;i=(i-1)&mask)ret=max(ret,cost[i]+Dp(mask^i));
    return ret;
}
void $olve()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    mxsubmasks((1<<n)-1);
    memset(dp,-1,sizeof(dp));
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