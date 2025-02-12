#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e4+1,Mod=1e9+7;
ll dp[2001][2001][2][2];
string a,b;
int m,d;
ll Dp(int i,int sum, bool Up,bool Low)
{
    if(i==sz(b))return !sum;
    ll &ret=dp[i][sum][Up][Low];
    if(~ret)return ret;
    ret=0;
    int Ulmt=Up?b[i]-'0':9;
    int Llmt=Low?a[i]-'0':0;
    for(int dgt=Llmt;dgt<=Ulmt;dgt++)
    {
        if(dgt==d&&i&1)ret+=Dp(i+1,(sum*10+dgt)%m,Up&(dgt==Ulmt),Low&(dgt==Llmt));
        else if(dgt!=d&&!(i&1))ret+=Dp(i+1,(sum*10+dgt)%m,Up&(dgt==Ulmt),Low&(dgt==Llmt));
        if(ret>=Mod)ret-=Mod;
    }
    return ret;
}
void $olve()
{
    cin>>m>>d;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    ll ans=Dp(0,0,1,1);
    cout<<ans<<enl;
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