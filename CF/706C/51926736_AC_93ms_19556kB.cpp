#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e5+5;
ll n;
ll dp[N][2];
vector<string>st,st_riv;
vector<ll>a;
ll Dp(ll i,ll j)
{
    if(i==n)return 0;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    // 0 First
    // 1 Last
    ret=1e18;
    if(!j)
    {
        if(st[i]>=st[i-1])ret=Dp(i+1,0);
        if(st_riv[i]>=st[i-1])ret=min(Dp(i+1,1)+a[i],ret);
    }
    else
    {
        if(st[i]>=st_riv[i-1])ret=min(ret,Dp(i+1,0));
        if(st_riv[i]>=st_riv[i-1])ret=min(Dp(i+1,1)+a[i],ret);
    }
    return ret;
}
void Suii()
{
   cin>>n;
   a.resize(n);
   st.resize(n);
   for(int i=0;i<n;i++)cin>>a[i];
   for(int i=0;i<n;i++)cin>>st[i];
   for(int i=0;i<n;i++)
   {
      string h=st[i];
      reverse(all(h));
      st_riv.push_back(h);
   }
   ::memset(dp,-1, sizeof dp);
   ll k=Dp(1,0);
   ::memset(dp,-1, sizeof dp);
   k=min(k,Dp(1,1)+a[0]);
   cout<<(k==1e18?-1:k);
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