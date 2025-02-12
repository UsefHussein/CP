#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e3+5,Mod=1e9+7;
int n;
ll dp[N][N];
char a[N][N];
ll Dp(int i=0,int j=0)
{
    if(i>=n||j>=n)return 0;
    if(i==n-1&&j==n-1)return 1;
    ll &ret=dp[i][j];
    if(~ret)return ret%Mod;
    ret=0;
    if(a[i+1][j]!='*')ret+= Dp(i+1,j)%Mod;
    if(a[i][j+1]!='*')ret+= Dp(i,j+1)%Mod;
    return ret%Mod;
}
void $olve()
{
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
    ::memset(dp,-1,sizeof dp);
    if(a[0][0]=='*')cout<<0;
    else cout<<Dp()%Mod;
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