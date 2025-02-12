#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

void $olve()
{
    int n;
    cin>>n;
    vector<int> a(n),mp(n+5);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]=i;
    }
    ll ans=1;
    for(int i=1;i<=n;i++)
    {
        if(mp[i]<mp[i-1])ans++;
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
    int T = 1;//cin>>T;
    while(T--)$olve();
    return 0;
}
