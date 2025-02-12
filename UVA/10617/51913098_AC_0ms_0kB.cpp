#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=100;
ll n;
string s;
vector<vector<ll>>dp;
ll Dp(ll i,ll j)
{
    if(i>j)return 0;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    ret=0;
    if(s[i]==s[j])ret+= Dp(i+1,j-1)+1;
    ret+= Dp(i+1,j);
    ret+= Dp(i,j-1);
    ret-= Dp(i+1,j-1);
    return ret;
}
void Suii()
{
    cin>>s;
    n=sz(s);
    dp.assign(N,vector<ll>(N,-1));
    cout<<Dp(0,n-1)<<enl;
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