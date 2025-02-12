#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x)  ll(x.size())
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e4+5,Mod=1e9+7;
int calc(int num,int m)
{
    int cnt=0;
    while(num%m==0)cnt++,num/=m;
    return cnt;
}
vector<int> Update_primeFact(int num)
{
    vector<int>v(4);
    v[0]= calc(num,2);
    v[1]= calc(num,3);
    v[2]= calc(num,5);
    v[3]= calc(num,7);
    return v;
}
vector<vector<int>>Pre(N+1);
void pre()
{
    for(int i=1;i<=1e4;i++)Pre[i] = Update_primeFact(i);
}
int n;
vector<int>a;
ll dp[N][4][3][2][2];
ll Dp(int i=0,int num2=0,int num3=0,int num5=0,int num7=0)
{
    if(i==n)return num2>=3&&num3>=2&&num5&&num7?1:0;
    ll &ret=dp[i][num2][num3][num5][num7];
    if(~ret)return ret%Mod;
    ret=0;
    ret+=Dp(i+1,min(3,num2+Pre[a[i]][0]),min(2,num3+Pre[a[i]][1])
    ,min(1,num5+Pre[a[i]][2]),min(1,num7+Pre[a[i]][3]))%Mod;
    ret+=Dp(i+1, num2,num3,num5,num7)%Mod;
    return ret%Mod;
}
void $olve()
{
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ::memset(dp,-1,sizeof dp);
    cout<<Dp();
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
    pre();
    int T = 1;
    //cin>>T;
    while(T--)$olve();
    return 0;
}