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
void Print(int i,int j)
{
    if(i>=j)
    {
        if(i==j)cout<<s[i];
        return;
    }
    ll &ret=dp[i][j];
    if(s[i]==s[j])
    {
        cout<<s[i];
        Print(i+1,j-1);
        cout<<s[i];
        return;
    }
    else if(Dp(i+1,j)+1==ret)
    {
        cout<<s[i];
        Print(i+1,j);
        cout<<s[i];
    }
    else
    {   cout<<s[j];
        Print(i,j-1);
        cout<<s[j];
    }
}
void Suii()
{
    while(cin>>s)
    {
        ::memset(dp, -1, sizeof(dp));
        cout << Dp(0, sz(s) - 1) << " ";
        Print(0, sz(s) - 1) ;
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