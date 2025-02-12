#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=2e5+5,M=1e9+7;
ll dp[N][65];
ll vis[N][65];
int n,k,id;
vector<int> a;
ll Dp(int i,int j)
{
    //cout<<i<<" "<<j<<" "<<" "<<__popcount(j)<<enl;
    if(i==n)return __popcount(j)==k;
    ll &ret=dp[i][j+1];
    if(vis[i][j+1]==id)return ret;
    vis[i][j+1]=id;
    ret=0;
    ret+=Dp(i+1,(a[i]&j));
    ret+=Dp(i+1,j);
    if(ret>=M)ret-=M;
    return ret;
}
void $olve()
{
    ++id;
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<Dp(0,-1)<<enl;
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
    int T = 1;cin>>T;
    while(T--)$olve();
    return 0;
}