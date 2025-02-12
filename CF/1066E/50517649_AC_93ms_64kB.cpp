#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double  dd;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
ll poow(ll x,ll y,ll mod)
{
    ll ans{1};
    while(y)
    {
        if(y&1)ans*=(x%mod);
        ans%=mod;
        x*=(x%mod);
        x%=mod;
        y/=2;
    }
    return (ans%mod);
}
string s,h;
void Equal()
{
    if(sz(s)>sz(h))
    {
        reverse(all(h));
        while(1)
        {
            h+='0';
            if(sz(h)==sz(s))break;
        }
        reverse(all(h));
    }
    else if(sz(s)<sz(h))
    {
        reverse(all(s));
        while(1)
        {
            s+='0';
            if(sz(h)==sz(s))break;
        }
        reverse(all(s));
    }
}
void Suii()
{
    int n,m;cin>>n>>m;
    cin>>s>>h;
    ll p,cnt=0,ans=0;
    Equal();
    //cout<<s<<" "<<h<<enl;
    p=sz(h)-1;m=sz(h);
    for(int i=0;i<m;i++)
    {
        if(h[i]=='1')cnt++;
        if(s[i]=='1')ans+=(poow(2,p,998244353))*cnt;
        ans%=998244353;
        p--;
    }
    cout<<ans;
}
void Fast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void File()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main() {
    Fast();
    File();
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}