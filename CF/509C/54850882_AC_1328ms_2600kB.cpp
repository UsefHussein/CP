#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(x) int(x.size())
#define F first
#define S second
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
const int N=401,Mod=1e9+7;
ll dp[N][N][2];
int n,target;
string s,m;
vector<ll>a;
ll Dp(int i,int sum,bool bo)
{
    if(sum>target)return 0;
    if(i==400)return sum==target&&!bo;
    ll &ret=dp[i][sum][bo];
    if(~ret)return ret;
    ret=0;
    int l=bo?s[i]-'0':0;
    for(int dgt=l;dgt<=9;dgt++)
    {
        ret|=Dp(i+1 , sum + dgt,bo&dgt==l);
    }
    return ret;
}
void build(int i,int sum,bool bo)
{
    if(i==400)return;
    int l=bo?s[i]-'0':0;
    ll &ret=dp[i][sum][bo];
    for(int dgt=l;dgt<=9;dgt++)
    {
        if(Dp(i+1 , sum + dgt,bo&dgt==l)==ret)
        {
            m+=to_string(dgt);
            build(i+1,sum+dgt,bo&l==dgt);
            return;
        }
    }
}
void $olve()
{
    while(sz(s)<=450)s+='0';
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)
    {
        memset(dp,-1,sizeof(dp));
        target=a[i];
        Dp(0,0,1);
        build(0,0,1);
        s=m;
        reverse(all(m));
        while(m.back()=='0')m.pop_back();
        cout<<string(rall(m))<<enl;
        m="";
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