#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x)  ll(x.size())
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=3e3+5,Mod=1e9+7;
ll n,k;
ll dp[N][N];
string s,m;
ll Dp(int i=0,int j=0)
{
    if(i>=n||j>=k)return 0;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    if(s[i]==m[j])ret=max(ret, Dp(i+1,j+1)+1);
    ret=max(ret, Dp(i,j+1));
    ret=max(ret, Dp(i+1,j));
    return ret;
}
void print(int i=0,int j=0)
{
    if(i>=n||j>=k)return;
    ll &ret=dp[i][j];
    if(s[i]==m[j])
    {
        cout<<s[i];
        print(i+1,j+1);
        return;
    }
    if(ret== Dp(i,j+1))print(i,j+1);
    else if(ret== Dp(i+1,j))print(i+1,j);
}
void $olve()
{
    cin>>s>>m;
    n=s.size(),k=m.size();
    ::memset(dp,-1,sizeof dp);
    Dp();
    print();
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