#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int) (s).size()

void $olve()
{
    ll a,b,c;
    cin>>a>>b>>c;
    vector<ll> v;
    for(ll i=1;i<=max(a,b); i++) {
        if(b%i==0 && a%i==0)
        {
            v.push_back(i);
        }
    }
    cout<<v[sz(v)-c];
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