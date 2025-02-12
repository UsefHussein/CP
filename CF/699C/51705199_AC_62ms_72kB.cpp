#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
// 1ll<<i متنساش ll
const int N=102;
ll dp[N][5],n;
vector<ll>a;
ll Dp(int i,int j)
{
    if(i==n)return 0;
    ll &ret=dp[i][j];
    if(ret!=1e18)return ret;
    if(a[i]==j||!a[i])ret=min(ret,Dp(i+1,0)+1);
    else if(a[i]==3)
    {
        if(j==1)ret=min(Dp(i+1,2),ret);
        else if(j==2)ret=min(Dp(i+1,1),ret);
        else ret=min({Dp(i+1,1),ret,Dp(i+1,2)});
    }
    else ret=min(Dp(i+1,a[i]),ret);
    return ret;
}
void Suii()
{
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<5;j++)dp[i][j]=1e18;
    }
    cout<<min({Dp(0,0),Dp(0,1),Dp(0,2),Dp(0,3)});
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