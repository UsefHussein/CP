#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
const int N=30,Mod=1e9+7;
const ll NN = -1000000000000 ;
ll poow(ll x,ll y)
{
    ll ans{1};
    while(y)
    {
        if(y&1)ans*=(x);
        x*=(x);
        y/=2;
    }
    return (ans);
}
vector<ll>P,a;
ll n,l;
map<ll,ll>dp;
ll Dp(ll k)
{
    if(k<=0)return 0;
    if(dp.count(k))return dp[k];
    ll &ret=dp[k];
    ret=1e18;
    for(int j=0;j<n;j++)
    {
        ll op = k / P[j];
        if(!op)op=1;
        ret = min(ret, Dp( k - (op * P[j])) + (op * a[j]));
    }
    return ret;
}
void Suii()
{
    cin>>n>>l;
    a.resize(n);
    P.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        P[i]=(poow(2,i));
    }
    cout<<Dp(l);
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