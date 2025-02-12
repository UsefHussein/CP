#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

int allsum,n;
vector<int>a;
ll dp[61][61*10000];
ll Dp(int i,int sum)
{
    if(i==n)return 0;
    ll &ret=dp[i][sum];
    if(~ret)return ret;
    ret=0;
    if(sum+a[i]>allsum/2&&sum<=allsum/2)ret++;
    ret+=Dp(i+1,sum);
    ret+=Dp(i+1,sum+a[i]);
    return ret;
}
void $olve()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.rbegin(),a.rend());
    allsum=accumulate(a.begin(),a.end(),0);
    cout<<Dp(0,0);
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
