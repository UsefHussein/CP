#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=2e3+5;
ll dp[N][N],mp[27];
int n,m;
string s,t;
ll Dp(int i,int j)
{
    if(i>=n||j>=m)return 0;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    if(s[i]==t[j])ret=Dp(i+1,j+1)+mp[s[i]-'a'];
    ret=max(ret,Dp(i+1,j));
    ret=max(ret,Dp(i,j+1));
    return ret;
}
void Suii()
{

   cin>>n>>m;
   for(int i=0;i<26;i++)cin>>mp[i];
   cin>>s>>t;
    ::memset(dp,-1, sizeof dp);
    cout<<Dp(0,0);
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