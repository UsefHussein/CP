#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long


void $olve()
{
    ll n,m;
    cin>>n>>m;
    n--;
    ll a=((n%4)+1)%4,b=((m%4)+1)%4;
    ll ans1=0,ans2=0;
    for(ll i=n-a+1;i<=n;i++)ans1^=i;
    for(ll i=m-b+1;i<=m;i++)ans2^=i;
    cout<<(ans1^ans2);
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