#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e5+2;
vector<ll>adj[N];
ll dp[N];
ll Dp(ll i)
{
    if(!sz(adj[i]))return 0;
    ll &ret=dp[i];
    if(~ret)return ret;
    for(auto j:adj[i])ret=max(ret, Dp(j)+1);
    return ret;
}
void Suii()
{
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
    }
    ::memset(dp,-1,sizeof dp);
    ll ans=-1e18;
    for(int i=1;i<=n;i++)ans=max(ans,Dp(i));
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
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}