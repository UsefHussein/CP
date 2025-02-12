#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
const int N=13;
ll dp[1<<N][99];
int n,k;
ll cnt=0;
ll Dp(int mask,int ans)
{

    if(__builtin_popcount(mask)==n)return ans==k?1:0;
    ll &ret=dp[mask][ans];
    if(~ret)return ret;
    ret=0;
    for(int i=0;i<n;i++)
    {
        if((mask>>i)&1)continue;
        int cnt=0;
        for(int j=i+1;j<n;j++)if((mask>>j)&1)cnt++;
        ret += Dp(mask | (1 << i), ans+cnt);
        //ret += Dp(mask , ans);
    }
    return ret;
}
void $olve()
{
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    cout<<Dp(0,0)<<enl;
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
signed main() {
    F_F();
    int T = 1;
    cin>>T;
    while(T--)$olve();
    return 0;
}