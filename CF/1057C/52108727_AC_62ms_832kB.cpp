#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
ll dp[52][2002],Vis[52];
ll n,p,k;
vector<int>a;
string s;
ll Dp(int i,int Cost)
{
    if(Cost>=k)return 0;
    ll &ret=dp[i][Cost];
    if(~ret)return ret;
    ret=1e18;
    for(int j=0;j<n;j++)
    {
        if(s[i]!=s[j]&&a[j]>a[i])
        {
            ret=min(ret,Dp(j,Cost+a[j])+abs(j-i));
        }
    }
    return ret;
}
void Suii()
{
    cin>>n>>p>>k;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>s;
    ll ans=1e18;
    for(int i=0;i<n;i++)
    {
        ::memset(dp, -1, sizeof dp);
        ans =min(ans, Dp(i,a[i])+abs(i-(p-1)));
    }
    cout<<(ans>1e3?-1:ans);
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