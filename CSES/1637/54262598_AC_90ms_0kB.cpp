#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e6+2,Mod=1e9+7;
int n;
ll dp[N];
ll Dp(int cut=n)
{
    if(cut<=0)return !cut?0:1e18;
    ll &ret=dp[cut];
    if(~ret)return ret;
    ret=1e18;
    string cur= to_string(cut);
    for(auto i:cur)
    {
        ll k=cut-(i-'0');
        if(i!='0')ret=min(ret, Dp(k)+1);
    }
    return ret;
}
void $olve()
{
    cin>>n;
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