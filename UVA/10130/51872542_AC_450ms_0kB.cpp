#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=3e3+5;
ll n,m;
vector<vector<ll>>dp,a;
int Target;
ll Dp(int i,int j)
{
    if(i>=n||j>=Target)return 0;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    if(j+a[i][1]<=Target)ret=Dp(i+1,j+a[i][1])+a[i][0];
    return ret=max(ret,Dp(i+1,j));
}
void Suii()
{
    cin>>n;
    a.resize(n+1,vector<ll>(2));
    for(int i=0;i<n;i++)for(int j=0;j<2;j++)cin>>a[i][j];
    cin>>m;
    ll ans=0;
    while(m--)
    {
        cin >> Target;
        dp.assign(n + 1, vector<ll>(100, -1));
        ans += Dp(0, 0);
    }
    cout<<ans<<enl;
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
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}