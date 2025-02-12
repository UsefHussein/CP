#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x)  ll(x.size())
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=3e3+5,Mod=1e9+7;
int n,Sum;
ll dp[502][(500*(501)/2)+2];
ll Dp(int i=1,int sum=0)
{
    if(i==n)return sum==(Sum-sum)?1:0;
    ll &ret=dp[i][sum];
    if(~ret)return ret%Mod;
    ret=0;
    ret+= Dp(i+1,sum+i)%Mod;
    ret+= Dp(i+1,sum)%Mod;
    return ret%Mod;
}
void $olve()
{
    cin>>n;
    Sum=n*(n+1)/2;
    ::memset(dp,-1, sizeof dp);
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