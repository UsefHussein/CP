#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(s) (int)s.size()
void $olve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> a(n);
    for(int i=0;i<n;i++)cin>>a[i].F>>a[i].S;
    sort(a.begin(),a.end());
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        ll op=min(a[i].S,m);
        sum+=op*a[i].F;
        m-=op;
        if(!m)break;
    }
    cout<<sum<<enl;
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
    int T = 1;//cin>>T;
    while(T--)$olve();
    return 0;
}
