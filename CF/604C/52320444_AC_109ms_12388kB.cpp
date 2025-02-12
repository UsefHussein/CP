#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e5+2;
ll dp[N][2][3];
int n;
string s;
ll Dp(int i,int bo,int flip)
{
    if (i == n)return 0;
    ll &ret = dp[i][bo][flip];
    if (~ret)return ret;
    //0       1   2
    //Before  in  next
    if(!flip)
    {

        if(bo&&s[i]=='1')ret = max(ret, Dp(i + 1, 0, 0)+1);
        else if(bo&&s[i]=='0')ret = max(ret, Dp(i + 1, 0, 1)+1);
        else if(!bo&&s[i]=='1')ret = max(ret, Dp(i + 1, 1, 1)+1);
        else if(!bo&&s[i]=='0')ret = max(ret, Dp(i + 1, 1, 0)+1);
        ret = max(ret, Dp(i + 1, bo, 0));
    }
    if(flip==1)
    {
        if(bo&&s[i]=='1')ret = max(ret, Dp(i + 1, 0, 2)+1);
        else if(bo&&s[i]=='0')ret = max(ret, Dp(i + 1, 0, 1)+1);
        else if(!bo&&s[i]=='1')ret = max(ret, Dp(i + 1, 1, 1)+1);
        else if(!bo&&s[i]=='0')ret = max(ret, Dp(i + 1, 1, 2)+1);
        ret = max(ret, Dp(i + 1, bo, 2));
    }
    if(flip==2)
    {
        if(!bo&&s[i]=='0')ret = max(ret, Dp(i + 1, 1, 2)+1);
        else if(bo&&s[i]=='1')ret = max(ret, Dp(i + 1, 0, 2)+1);
        ret = max(ret, Dp(i + 1, bo, 2));
    }
    return ret;
}
void Suii()
{
    cin>>n>>s;
    ::memset(dp,-1,sizeof dp);
    ll ans=Dp(0,0,0);
    //cout<<ans<<enl;
    ::memset(dp,-1,sizeof dp);
    cout<<min(sz(s),max(ans,Dp(0,1,0)));
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