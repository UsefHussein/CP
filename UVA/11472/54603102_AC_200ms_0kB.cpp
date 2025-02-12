#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
const int N=101,Mod=1e9+7;
ll dp[N][12][1<<10];
int n,m;
ll Dp(int j,int prevdigit,int mask)
{
    int num=0;
    for(int i=0;i<=n-1;i++)if(!((mask>>i)&1))num++;
    if(j>m)return 0;
    ll &ret=dp[j][prevdigit][mask];
    if(~ret)return ret;
    ret=0;
    if(!num)ret++;
    for(int k=0;k<=n-1;k++)
    {
        if(abs(prevdigit-k)!=1&&prevdigit!=11)continue;
        if(!j&&!k)continue;
        ret += Dp(j+1,k,mask|1<<k);
        if(ret>=Mod)ret-=Mod;
    }
    return ret;
}
void $olve()
{
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    cout<<Dp(0,11,0)<<enl;
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