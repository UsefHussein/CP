#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int)s.size()
void $olve()
{
    string s;
    cin >> s;
    ll fr[200]={0};
    for (ll i = 0; i < sz(s); i++)fr[s[i]]++;
    ll ans=min({fr['T'],fr['A'],fr['P']});
    fr['T']-=ans;
    fr['P']-=ans;
    ans+=min({fr['T'],fr['U'],fr['P']});
    cout<<ans;
}
void F_F()
{
    cin.tie(0)->sync_with_stdio(0);
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