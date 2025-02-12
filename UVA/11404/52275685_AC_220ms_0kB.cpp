#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e3+2;
ll dp[N][N];
string s;
ll Dp(int i,int j)
{
    if(i>j)return 0;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    ret=1e18;
    if(s[i]==s[j])ret=min(ret,Dp(i+1,j-1));
    ret=min(ret,Dp(i+1,j)+1);
    ret=min(ret,Dp(i,j-1)+1);
    return ret;
}
bool Vis[N][N];
string Print_dp[N][N];
string Print(int i,int j)
{
    if(i>=j)
    {
        if(i==j)return s.substr(i,1);
        return "";
    }
    if(Vis[i][j])return Print_dp[i][j];
    Vis[i][j]=1;
    ll &ret=dp[i][j];
    string mn="}";
    if(s[i]==s[j])
    {
         mn=min(mn, s.substr(i,1)+Print(i+1,j-1)
                                          +s.substr(j,1));
    }
    if(Dp(i,j-1)+1==ret)
    {
        mn=min(mn, Print(i,j-1));
    }
    if(Dp(i+1,j)+1==ret) mn=min(mn, Print(i+1,j));
    return Print_dp[i][j]=mn;
}
void Suii()
{
    while(cin>>s)
    {
        ::memset(dp, -1, sizeof(dp));
        ::memset(Vis, 0, sizeof(Vis));
        Dp(0, sz(s) - 1);
        cout<<Print(0, sz(s) - 1) ;
        cout<<enl;
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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}