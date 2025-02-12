#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
// 1ll<<i متنساش ll
const int N=1e4+5;
ll n,d,dp[N][102];
vector<ll>a;

ll Dp(ll i,ll sum=0)
{
    if(i>=n)
    {
        if(!(sum%d))return 1;
        return 0;
    }
    ll& ret=dp[i][sum%d];
    if(~ret)return ret;
    ret=Dp(i+1,sum+a[i])||Dp(i+1,sum-a[i]);
    return ret;
}
void Suii()
{
    cin>>n>>d;
    a=vector<ll>(n);
    ::memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)cin>>a[i];
    if(Dp(1,a[0]))cout<<"Divisible";
    else cout<<"Not divisible";
    cout<<enl;
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