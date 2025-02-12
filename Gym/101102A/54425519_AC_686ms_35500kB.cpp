#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
const int N=31,Mod=1e9+7;
ll dpHassan[151][15001];
ll dpHamoksha[151][15001];
int n,m,w,k;
vector<int>Hassan,Hamoksha;
ll Dp2(int i,int sum)
{
    if(i==m)return !sum?1:0;
    ll &ret=dpHamoksha[i][sum];
    if(~ret)return ret;
    ret=0;
    if(sum-Hamoksha[i]>=0)ret+= Dp2(i+1,sum-Hamoksha[i])%Mod;
    ret+= Dp2(i+1,sum)%Mod;
    return ret%Mod;
}
ll Dp1(int i,int sum)
{
    if(i==n)return !sum?1:0;
    ll &ret=dpHassan[i][sum];
    if(~ret)return ret;
    ret=0;
    ret+=Dp1(i+1,sum)%Mod;
    if(sum-Hassan[i]>=0)ret+=Dp1(i+1,sum-Hassan[i])%Mod;
    return ret;
}
void $olve()
{
    cin>>n>>m>>k>>w;
    Hassan.resize(n);
    Hamoksha.resize(m);
    for(int i=0;i<n;i++)cin>>Hassan[i];
    for(int i=0;i<m;i++)cin>>Hamoksha[i];
    ::memset(dpHassan,-1,sizeof dpHassan);
    ::memset(dpHamoksha,-1,sizeof dpHamoksha);
    ll ans=0;
    for(int i=0;i<=w;i++)
    {
        if(abs(i-(w-i))<=k)ans += Dp1(0, i) * Dp2(0, w - i);
        ans%=Mod;
    }
    cout<<ans<<enl;
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
    cin>>T;
    while(T--)$olve();
    return 0;
}