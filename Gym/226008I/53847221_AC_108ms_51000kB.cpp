#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
const int N=1e6+5,Mod=1e9+7;
int n,x;
vector<ll>a;
ll dp[51][2501][51];
ll Dp(int i,int sum,int cnt)
{
    if(i==n)
    {
        if(sum&&sum%cnt==0&&sum/cnt==x)return 1;
        return 0;
    }
    ll &ret=dp[i][sum][cnt];
    if(~ret)return ret;
    ret=0;
    ret+=Dp(i+1,sum,cnt);
    ret+=Dp(i+1,sum+a[i],cnt+1);
    return ret;
}
void Solve()
{
    cin>>n>>x;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ::memset(dp,-1,sizeof dp);
    cout<<Dp(0,0,0);
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
    while(T--) Solve();
    return 0;
}