#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e5+2,Mod=1e9+7;
vector<int>a[N];
ll dp[N][2];
int n;
ll Dp(int i,int u,int prev)
{
    ll &ret=dp[i][u];
    if(~ret)return ret%Mod;
    ret=1;
    for(auto j:a[i])
    {
        if (j == prev)continue;
        if (u)ret *= Dp(j, 0, i) % Mod;
        else ret *= (Dp(j, 0, i) + Dp(j, 1, i)% Mod) ;
        ret%=Mod;
    }
    return ret%Mod;
}
void $olve()
{
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    ::memset(dp,-1,sizeof dp);
    ll mx=-1;
    mx=max(mx, Dp(1,0,-100)%Mod+Dp(1,1,-100)%Mod);
    cout<<mx%Mod;
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
signed main()
{
    F_F();
    int T = 1;
    //cin>>T;
    while(T--)$olve();
    return 0;
}