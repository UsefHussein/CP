#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define int long long

void $olve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin>>v[i];

    map<int, int> mp;
    mp[0]++;
    ll ans=0,sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=v[i];
        ll op=sum-k;
        if(mp.count(op))
            ans+=mp[op];

        mp[sum]++;
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