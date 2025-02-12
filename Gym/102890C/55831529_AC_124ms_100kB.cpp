#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int Mod=1e9+7;

void $olve()
{
    ll a,b;
    cin>>a>>b;
    a++;
    ll ans=a*(a+1)/2;
    ans=ans%Mod;
    ans*=b+1;
    ans=ans%Mod;
    cout<<ans<<enl;
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
    cin>>T;
    while(T--)$olve();
    return 0;
}