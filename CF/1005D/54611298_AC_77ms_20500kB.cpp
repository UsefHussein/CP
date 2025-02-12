#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
const int N=2e5+1,Mod=1e9+7;
ll dp[N][3];
string s;
ll Dp(int i,int div)
{
    if(i==sz(s))return !div?1:0;
    ll &ret=dp[i][div];
    if(~ret)return ret;
    ret=-1e18;
    if(!div)ret=max(Dp(i+1,(s[i]-'0')%3)+1,ret);
    ret=max(Dp(i+1,(div*10+(s[i]-'0'))%3),ret);
    ret=max(Dp(i+1,(s[i]-'0')%3),ret);
    return ret;
}
void $olve()
{
    cin>>s;
    memset(dp,-1,sizeof(dp));
    cout<<Dp(1,(s[0]-'0')%3);
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