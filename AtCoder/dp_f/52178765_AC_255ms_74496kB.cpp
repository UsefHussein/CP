#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=3e3+2;
string s,t;
ll dp[N][N];
ll Dp(int i,int j)
{
    if(i==sz(s)||j==sz(t))return 0;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    if(s[i]==t[j])ret=max(ret,Dp(i+1,j+1)+1);
    ret=max(ret,Dp(i,j+1));
    ret=max(ret,Dp(i+1,j));
    return ret;
}
void Build(int i,int j)
{
    if(i==sz(s)||j==sz(t))return;
    ll &ret=dp[i][j];
    if(s[i]==t[j])
    {
        cout<<s[i];
        Build(i+1,j+1);
        return;
    }
    else if(ret==Dp(i+1,j))Build(i+1,j);
    else Build(i,j+1);
}
void Suii()
{
    cin>>s>>t;
    ::memset(dp,-1,sizeof dp);
    Dp(0,0);
    Build(0,0);
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