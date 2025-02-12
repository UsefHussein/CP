#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e3+5;
string s;
ll dp[N][N];
ll Dp(ll i,ll j)
{
    if(i>j)return 0;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    ret=Dp(i+1,j-1)+(s[i]!=s[j]);
    ret=min(ret,Dp(i+1,j)+1);
    ret=min(ret,Dp(i,j-1)+1);
    return ret;
}
void Suii()
{
    int t;cin>>t;
    for(int u=1;u<=t;u++)
    {
        cin >> s;
        ::memset(dp, -1, sizeof dp);
        ll ans = Dp(0, sz(s) - 1);
        //Case 1: 5
        cout <<"Case "<<u<<": "<< ans<<enl;
    }
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