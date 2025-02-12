#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int) (s).size()

void $olve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum=0,ans=0,mx=0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum+=a[i];
        ans+=sum;
        mx=max(mx,a[i]);
        cout<<ans+mx*(i+1)<<enl;
    }

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