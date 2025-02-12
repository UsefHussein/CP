#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e2+5;
ll n,m,k;
ll dp[N][N][N],Amount[N][N];
vector<ll>a;
ll Dp(int i,int j, int c,int prev)
{
    if(i==n)
    {
        if(!c)return 0;
        return 1e18;
    }
    ll &ret=dp[i][j][c];
    if(~ret)return ret;
    ret=1e18;
    if(a[i]&&prev!=a[i])ret=Dp(i+1,j,c-1,a[i]);
    if(a[i]&&prev==a[i])ret=min(ret,Dp(i+1,j,c,a[i]));
    if(!a[i])
    {
        for(int z=1;z<=m;z++)
        {
            if(z==prev)ret=min(ret,Dp(i+1,z,c,z)+Amount[i][z-1]);
            if(z!=prev)ret=min(ret,Dp(i+1,z,c-1,z)+Amount[i][z-1]);
        }

    }
    return ret;
}
void Suii()
{
   cin>>n>>m>>k;
   a.resize(n);
   for(int i=0;i<n;i++)cin>>a[i];
   for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>Amount[i][j];
   ::memset(dp,-1,sizeof dp);
   ll ans=Dp(0,0,k,0);
   for(int i=1;i<=m;i++)ans=min(ans,Dp(0,i,k,0));
   cout<<(ans==1e18?-1:ans);
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