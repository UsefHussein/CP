#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
ll GetBit(ll n,int i)
{
    return (n>>i)&1ll;
}
int Dis(pair<int,int>&a,pair<int,int>&b) {
    int ans=abs(a.F-b.F)+abs(a.S-b.S);
    return ans;
}
const int N=11,Mod=1e9+7;
ll dp[N][1<<N];
int n,m,t;
int x,y;
vector<pair<int,int>>a;
ll Dp(int i,int mask)
{
    if(__builtin_popcount(mask)==t+1)
        return Dis(a[i],a[0]);
    ll &ret=dp[i][mask];
    if(~ret)return ret;
    ret=1e18;
    for(int c=1;c<=t;c++)
    {
        if(GetBit(mask,c))continue;
        ret=min(ret,Dp(c,mask|(1<<c))+Dis(a[i],a[c]));
    }
    return ret;
}
void $olve()
{
    cin>>n>>m;
    cin>>x>>y;
    cin>>t;
    a.resize(t+1);
    a[0]={x,y};
    for(int i=1;i<=t;i++)cin>>a[i].F>>a[i].S;
    memset(dp,-1,sizeof(dp));
    ll mn=1e18;
    for(int i=1;i<=t;i++)mn=min(mn,Dp(i,1)+Dis(a[i],a[0]));
    cout<<"The shortest path has length ";
    cout<<mn<<enl;
}
void F_F()
{
    std::ios_base::sync_with_stdio();
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