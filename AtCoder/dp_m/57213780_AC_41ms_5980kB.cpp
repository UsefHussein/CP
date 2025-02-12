#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

ll dp[2][100001];
int n,mod=1e9+7;
vector<int> a;
void $olve()
{
    ll k;
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    dp[n&1][0]=1;
    for(int i=n-1;i>=0;i--)
    {
        vector<ll>rem(k+2);
        rem[0]=dp[(i+1)&1][0];
        for(int j=0;j<=k;j++)dp[i&1][j]=0;
        for(int sum=1;sum<=k;sum++)
        {
            rem[sum]=dp[(i+1)&1][sum]+rem[sum-1];
            if(rem[sum]>=mod)rem[sum]-=mod;
        }
        for(int sum=0;sum<=k;sum++)
        {
            int l=max(0,sum-a[i]),r=sum;
            ll &ret=dp[i&1][sum];
            ret+=rem[r]-(!l?0:rem[l-1]);
            ret+=mod;
            if(ret>=mod)ret-=mod;
        }
    }
    cout<<dp[0][k]<<enl;
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
