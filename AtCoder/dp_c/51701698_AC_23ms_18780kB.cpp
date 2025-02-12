#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
// 1ll<<i متنساش ll
ll n;
const int N=1e5+2;
ll dp[N][3];
vector<vector<ll>>a;
ll rec(ll i,int j)
{
    if(i==n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll mx=0;
    if(j==0)mx=max({rec(i+1,1)+a[i][1],rec(i+1,2)+a[i][2]});
    if(j==1)mx=max({rec(i+1,0)+a[i][0],rec(i+1,2)+a[i][2]});
    if(j==2)mx=max({rec(i+1,1)+a[i][1],rec(i+1,0)+a[i][0]});
    dp[i][j]=mx;
    return dp[i][j];
}
void Suii()
{
        cin >> n;
        a=vector<vector<ll>>(n,vector<ll>(3));
        memset(dp,-1,sizeof (dp));
        for (int i = 0; i < n; i++)for(int j=0;j<3;j++)cin>>a[i][j];
        cout <<max({rec(0,0),rec(0,1),rec(0,2)})<<enl;
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