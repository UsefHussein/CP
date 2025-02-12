#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
// 1ll<<i متنساش ll
ll n,k;
const int N=1e5+2;
ll dp[N];
vector<ll>a;
ll rec(ll i)
{
    if(i>=n-1)return 0;
    //cout<<dp[i]<<enl;
    if(dp[i]!=1e18)return dp[i];
    for(int j=1;j<=k;j++)
    {
        if(i+j<n)dp[i]=min({dp[i], rec(i+j)+abs(a[i]-a[i+j])});
    }
    return dp[i];
}
void Suii()
{
        cin >> n;
        k=2;
        a.resize(n);
        for(int i=0;i<N;i++)dp[i]=1e18;
        for (int i = 0; i < n; i++)cin >> a[i];
        cout <<rec(0)<<enl;
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
int32_t main()
{
    F_F();
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}