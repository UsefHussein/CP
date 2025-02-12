#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
const int N=13,Mod=1e9+7;
ll GetBit(ll n,int i)
{
    return (n>>i)&1ll;
}
ll Cnt(int k) {
    ll cnt=0;
    for(int i=0;i<=12;i++)if(GetBit(k,i))cnt++;
    return cnt;
}
ll dp[N][1<<N];
int n;
ll Dp(int i,int mask)
{
    //cout<< i<< " "<<mask<<endl;
    if(i==n||i<0)return Cnt(mask);
    ll &ret = dp[i][mask];
    if(~ret)return ret;
    ret=15;
    ret=min(ret,Dp(i+1,mask));
    if(i>1&&GetBit(mask,i)&&GetBit(mask,i-1)&&!GetBit(mask,i-2))
    {
            int New=mask|(1<<(i-2));
            New=New&~(1<<i);
            New=New&~(1<<i-1);
            ret=min(ret,Dp(0,New));
    }
    if(i<10&&GetBit(mask,i)&&GetBit(mask,i+1)&&!GetBit(mask,i+2))
    {
            int New=mask|(1<<(i+2));
            New=New&~(1<<i);
            New=New&~(1<<i+1);
            ret=min(ret,Dp(0,New));
    }
    return ret;
}
void $olve()
{
    string s;cin>>s;
    n=sz(s);
    int k=0;
    for(int i=0;i<n;i++)if(s[i]=='o')k=k|(1<<i);
    memset(dp,-1,sizeof(dp));
    cout<<Dp(0,k)<<enl;
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