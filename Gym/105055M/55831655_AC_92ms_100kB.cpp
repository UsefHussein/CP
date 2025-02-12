#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int Mod=1e9+7;

void $olve()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(m);
    for(int i=0;i<m;i++)cin>>a[i];
    sort(a.begin(),a.end());
    ll ans=max(a[0],n-a.back());
    for(int i=1;i<m;i++)
    {
        ll op=a[i]-a[i-1];
        ans=max((op/2)+(op&1),ans);
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

signed main()
{
    F_F();
    int T = 1;
    //cin>>T;
    while(T--)$olve();
    return 0;
}