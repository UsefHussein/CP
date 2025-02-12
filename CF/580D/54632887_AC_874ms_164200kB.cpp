#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
const int N=20,Mod=1e9+7;
ll GetBit(ll n,int i)
{
    return (n>>i)&1ll;
}
vector<int>mp[20];
vector<int>a;
int n,m;
ll dp[1<<N][N];
bool bo[N][N];
int co[N][N];
ll Dp(int mask,int prev)
{
    if(__popcount(mask)==m)return 0;
    ll &ret=dp[mask][prev];
    if(~ret)return ret;
    ret=-1e18;

    for(int i=0;i<n;i++)
    {
        if(GetBit(mask,i))continue;
        if(bo[prev][i])ret=max(ret,Dp(mask|(1<<i),i)+co[prev][i]+a[i]);
        ret=max(ret,Dp(mask|(1<<i),i)+a[i]);
    }
    return ret;
}
void $olve()
{
    int k;
    cin>>n>>m>>k;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<k;i++)
    {
        int x,y,cost;
        cin>>x>>y>>cost;
        x--,y--;
        mp[x].push_back(y);
        co[x][y]=cost;
        bo[x][y]=1;
    }
    memset(dp,-1,sizeof(dp));
    cout<<Dp(0,19)<<enl;
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