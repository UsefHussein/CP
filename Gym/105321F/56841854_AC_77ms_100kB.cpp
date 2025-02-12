#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int)s.size()
void $olve()
{
    int n;
    cin >> n;
    ll ans=0;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++) {
        if(a[i])ans++;
        else ans--;
    }
    for(int i=2;i<n;i++)
    {
        if(a[i]==1&&a[i-1]==1&&a[i-2]==1)ans++;
    }
    cout<<ans<<enl;
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