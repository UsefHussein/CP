#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

ll x,y,z,n;
const int N=3e5+2;
ll dp[N][2];
string s;
ll Dp(int i,bool on)
{
    if(i==n)return 0;
    ll &ret=dp[i][on];
    if(~ret)return ret;
    ret=1e18;
    if(on)
    {
        if(s[i]=='A')ret=min(ret,Dp(i+1,on)+x);
        if(s[i]=='A')ret=min(ret,Dp(i+1,0)+z+x);
        if(s[i]=='A')ret=min(ret,Dp(i+1,0)+z+y);
        if(s[i]=='a')ret=min(ret,Dp(i+1,on)+y);
        if(s[i]=='a')ret=min(ret,Dp(i+1,0)+z+x);
    }
    else
    {
        if(s[i]=='a')ret=min(ret,Dp(i+1,on)+x);
        if(s[i]=='a')ret=min(ret,Dp(i+1,1)+z+x);
        if(s[i]=='a')ret=min(ret,Dp(i+1,1)+z+y);
        if(s[i]=='A')ret=min(ret,Dp(i+1,on)+y);
        if(s[i]=='A')ret=min(ret,Dp(i+1,1)+z+x);
    }
    return ret;
}
void $olve()
{
    cin>>x>>y>>z;
    cin>>s;
    n=s.size();
    memset(dp,-1,sizeof(dp));
    cout<<Dp(0,0)<<enl;
}
void F_F()
{
    cin.tie(0)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

signed main()
{
    F_F();
    int T = 1;//cin>>T;
    while(T--)$olve();
    return 0;
}