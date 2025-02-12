#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

ll dp[1001][501];
ll dp2[1001][501];
int n,c,l,ans;
vector<int> a;
ll calc(ll p) {
    ll res = 0;
    if(p>=1&&p<=10)res=-c;
    if(p>10)res=(p-10)*(p-10);
    return res;
}
ll Dp(int i,int sum)
{
    if(i==n)return 1;
    ll &ret = dp[i][sum];
    if(~ret)return ret;
    ret=1e18;
    if(sum+a[i]>l)ret=min(ret,Dp(i+1,a[i])+1);
    else ret=min(ret,Dp(i+1,sum+a[i]));
    ret=min(ret,Dp(i+1,a[i])+1);
    return ret;
}
ll build(int i,int sum)
{
    ll p=l-sum;
    if(i==n)return calc(p);
    ll &ret2 = dp[i][sum];
    ll &ret = dp2[i][sum];
    if(~ret)return ret;
    ret=1e18;
    if(sum+a[i]>l&&ret2==Dp(i+1,a[i])+1)
        ret=min(ret,build(i+1,a[i])+calc(p));
    if(sum+a[i]<=l&&ret2==Dp(i+1,sum+a[i]))
        ret=min(ret,build(i+1,sum+a[i]));
    if(ret2==Dp(i+1,a[i])+1)
        ret=min(ret,build(i+1,a[i])+calc(p));
    return ret;
}
int id=1;
void $olve()
{
    while(cin>>n)
    {
        if(!n)return;
        if(id!=1)cout<<enl;
        cin>>l>>c;
        a.resize(n);
        for(int i=0;i<n;i++)cin>>a[i];
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        cout<<"Case "<<id++<<":\n";
        cout<<"Minimum number of lectures: "<<Dp(0,0)<<enl;
        cout<<"Total dissatisfaction index: "<<build(0,0)<<enl;
    }
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
