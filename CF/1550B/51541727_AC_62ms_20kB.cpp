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
int a,b;
ll sol(string s,int p)
{
    ll ans=0;
    if(p==1)
    {
        ll cnt=0;
        for(int i=0;i<sz(s);i++)
        {
            if(s[i]=='1')cnt++;
            else if(s[i]=='0'&&cnt)
            {
                ans+=(cnt*a)+b;
                cnt=0;
            }
        }
        if(cnt)ans+=(cnt*a)+b;
        if(count(all(s),'0')>0)ans+= (count(all(s),'0')*a)+b;
    }
    else
    {
        ll cnt=0;
        for(int i=0;i<sz(s);i++)
        {
            if(s[i]=='0')cnt++;
            else if(s[i]=='1'&&cnt)
            {
                ans+=(cnt*a)+b;
                cnt=0;
            }
        }
        if(cnt)ans+=(cnt*a)+b;
        if(count(all(s),'1')>0)ans+=(count(all(s),'1')*a)+b;
    }
    return ans;
}
void Suii()
{
    int n;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    ll mx=n*(a+b);
    mx=max(mx,sol(s,1));
    mx=max(mx,sol(s,0));
    cout<<mx<<enl;
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
int32_t main()
{
    Fast();
    File();
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}