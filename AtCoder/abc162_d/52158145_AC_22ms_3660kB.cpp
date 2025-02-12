#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
string s;
int n;
ll Calc(vector<ll>&r)
{
    ll cnt=0;
    for(int i=0;i<sz(r);i++)
    {
        ll op=1;
        while(1)
        {
            if(r[i]-op<0||r[i]+op>=n)break;
            if(s[r[i]]!=s[r[i]+op]&&s[r[i]]!=s[r[i]-op]&&s[r[i]-op]!=s[r[i]+op])cnt++;
            op++;
        }
    }
    return cnt;
}
void Suii()
{
    cin>>n;
    vector<ll>r,g,b;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R')r.push_back(i);
        if(s[i]=='G')g.push_back(i);
        if(s[i]=='B')b.push_back(i);
    }
    ll ans=sz(g)*sz(b)*sz(r);
    ans-= Calc(r);
    ans-= Calc(g);
    ans-= Calc(b);
    cout<<ans;
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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}