#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e4+1,Mod=1e9+7;
ll dp[20][2][2][4][2];
string a,b;
ll Dp(int i, bool Up,bool Low,int ifnotZ,bool Z)
{
    if(i==sz(b))return 1;
    ll &ret=dp[i][Up][Low][ifnotZ][Z];
    if(~ret)return ret;
    ret=0;
    int Ulmt=Up?b[i]-'0':9;
    int Llmt=Low?a[i]-'0':0;
    for(int dgt=Llmt;dgt<=Ulmt;dgt++)
    {
        if(ifnotZ==3&&dgt&&!Z)continue;
        ret+=Dp(i+1,Up&(dgt==Ulmt),Low&(dgt==Llmt),
            dgt?ifnotZ+1:ifnotZ,Z&!dgt);
    }
    return ret;
}
void $olve()
{
    cin>>a>>b;
    reverse(all(a));
    while(sz(a)!=sz(b))a+='0';
    reverse(all(a));
    memset(dp,-1,sizeof(dp));
    ll ans=Dp(0,1,1,0,1);
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
    cin>>T;
    while(T--)$olve();
    return 0;
}