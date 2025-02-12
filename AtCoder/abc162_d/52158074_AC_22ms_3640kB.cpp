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
            if(s[r[i]-op]==s[r[i]+op])cnt++;
            op++;
        }
    }
    return cnt;
}
void Suii() {
    cin >> n;
    vector <ll> r, g, b, prb(n), prg(n), prr(n);
    cin >> s;
    ll cntr1 = count(all(s),'R');
    ll cntg1 = count(all(s),'G');
    ll cntb1 =count(all(s),'B');
    ll cntr2 = 0, cntg2 = 0, cntb2 = 0,ans=0;
    for (int i = 0; i < n; i++)
    {
        ll op=1;
        if(s[i]=='R')cntr2++;
        if(s[i]=='G')cntg2++;
        if(s[i]=='B')cntb2++;
        if(s[i]=='R')ans+=(cntg2*(cntb1-cntb2))+((cntg1-cntg2)*cntb2);
        if(s[i]=='G')ans+=(cntr2*(cntb1-cntb2))+(cntb2*(cntr1-cntr2));
        if(s[i]=='B')ans+=(cntg2*(cntr1-cntr2))+((cntg1-cntg2)*cntr2);
        while(1)
        {
            if(i-op<0||i+op>=n)break;
            if(s[i]!=s[i-op]&&s[i-op]!=s[i+op]&&s[i]!=s[i+op])ans--;
            op++;
        }
    }
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