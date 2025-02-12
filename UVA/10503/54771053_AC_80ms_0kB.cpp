#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(x) int(x.size())
#define F first
#define S second
const int N=17,Mod=1e9+7;
int n,m;
vector<pair<int,int>> a;
ll dp[N][1<<N][2];
ll Dp(int i,int mask,int is)
{
    if(__builtin_popcount(mask)==n)
    {
        if(is)return (a[i].S==a[1].F);
        return (a[i].F==a[1].F);
    }
    ll &ret = dp[i][mask][is];
    if(~ret) return ret;
    ret=0;
    for(int j=2;j<m+2;j++)
    {
        if((mask>>j)&1)continue;
        if(!is)
        {
            if(a[i].F==a[j].F)ret|=Dp(j,mask|(1<<j),1);
            else if(a[i].F==a[j].S)ret|=Dp(j,mask|(1<<j),0);
        }
        else
        {
            if(a[i].S==a[j].F)ret|=Dp(j,mask|(1<<j),1);
            else if(a[i].S==a[j].S)ret|=Dp(j,mask|(1<<j),0);
        }
    }
    return ret;
}
void $olve()
{
    while(cin>>n>>m)
    {
        if(!n)return;
        a.resize(m+2);
        for(int i=0;i<m+2;i++)cin>>a[i].F>>a[i].S;
        memset(dp,-1,sizeof(dp));
        bool bo=0;
        bo=Dp(0,0,1);
        memset(dp,-1,sizeof(dp));
        //bo|=Dp(0,0,0);
        cout<<(bo?"YES":"NO")<<enl;
    }
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