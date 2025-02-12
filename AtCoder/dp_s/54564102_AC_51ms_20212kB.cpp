#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e4+1,Mod=1e9+7;
ll dp[N][101][2];
string s;
int d;
ll Dp(int i, int sum,bool Up)
{
    if(i==sz(s))return !sum;
    ll &ret=dp[i][sum][Up];
    if(~ret)return ret;
    ret=0;
    int Ulmt=Up?s[i]-'0':9;
    for(int dgt=0;dgt<=Ulmt;dgt++)
    {
        ret += Dp(i+1,(sum+dgt)%d,Up&(dgt==Ulmt));
        if(ret>=Mod)ret-=Mod;
    }
    return ret;
}
void $olve()
{
    cin>>s>>d;
    memset(dp,-1,sizeof(dp));
    int ans=Dp(0,0,1)-1;
    cout<<(ans<0?ans+Mod:ans)<<enl;
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