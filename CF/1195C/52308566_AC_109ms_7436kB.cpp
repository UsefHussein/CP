#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e5+1;
ll dp[N][2];
int n;
vector<ll>a,b;
ll Dp(int i,int bo)
{

    if(i==n)return 0;
    ll &ret=dp[i][bo];
    if(~ret)return ret;
    ret=-1e18;
    ret=max(ret,Dp(i+1,0));
    ret=max(ret,Dp(i+1,1));
    if(!bo)ret=max(ret,Dp(i+1,1)+b[i]);
    if(bo)ret=max(ret,Dp(i+1,0)+a[i]);
    return ret;
}
void Suii()
{
   cin>>n;
   a.resize(n);
   b.resize(n);
   for(int i=0;i<n;i++)cin>>a[i];
   for(int i=0;i<n;i++)cin>>b[i];
   ::memset(dp,-1,sizeof dp);
   ll k=Dp(0,0);
   ::memset(dp,-1,sizeof dp);
   cout<<max(k, Dp(0,1));
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