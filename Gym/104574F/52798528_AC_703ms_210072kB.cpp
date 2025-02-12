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
const int N=1e4+1,Mod=1e9+7;
const ll NN = -1000000000000 ;
int n;
vector<pair<ll,ll>>a;
vector<vector<vector<ll>>>dp;
ll Dp(int i,int j,int c)
{
    if(j<0||c<0)return 
-1e18;
    if(i==n)return 0;
    ll &ret=dp[i][j][c];
    if(~ret)return ret;
    ret=-1e18;
    ret=max(ret, Dp(i+1,j,c));
    if(j>0)ret=max(ret, Dp(i+1,j-1,c)+a[i].F);
    if(c>0)ret=max(ret, Dp(i+1,j,c-1)+a[i].S);
    return ret;
}
void Suii()
{
    ll j,c;
    cin>>n>>j>>c;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i].F>>a[i].S;
    dp=vector<vector<vector<ll>>>(n+2,vector<vector<ll>>(j+2,vector<ll>(c+2,-1)));
    ll ans=Dp(0,j,c);
    cout<<ans;
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