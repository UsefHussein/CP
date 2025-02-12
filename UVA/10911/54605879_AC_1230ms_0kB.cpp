#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
const int N=17,Mod=1e9+7;
double Dis(int x1,int y1,int x2,int y2) {
    ll op1=x2-x1;op1*=op1;
    ll op2=y2-y1;op2*=op2;
    return sqrt(op1+op2);
}
vector<pair<ll,ll>>a;
int n;
double dp[N][1<<N];
double Dp(int i,int mask)
{
    //cout<<i<<" "<<mask<<" "<<endl;
    if(i==n)
    {
        int num=0;
        for(int t=0;t<n;t++)if(!((mask>>t)&1))num++;
        return !num?0:1e18;
    }
    double &ret=dp[i][mask];
    if(ret!=-1)return ret;
    ret=1e18;
    ret=min(ret,Dp(i+1,mask));
    for(int j=0;j<n;j++)
    {
        if(mask&(1<<j)||i==j||mask&(1<<i))continue;
        ret=min(ret,Dp(i+1,(mask|(1<<j))|(1<<i))+
            Dis(a[i].F,a[i].S,a[j].F,a[j].S));
    }
    return ret;
}
void $olve()
{
    int o=1;
    while(cin>>n)
    {
        if(!n)return;
        n*=2;
        a.resize(n);
        for(int i=0;i<n;i++)
        {
            string s;cin>>s;
            cin>>a[i].F>>a[i].S;
        }
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=(1<<n);j++)dp[i][j]=-1;
        }
        cout<<"Case "<<o++<<": ";
        cout<<setprecision(2)<<fixed<<Dp(0,0)<<enl;
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