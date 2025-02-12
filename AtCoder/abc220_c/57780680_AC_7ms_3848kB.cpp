#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long


void $olve()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    ll k;
    cin>>k;
    ll sum=accumulate(a.begin(),a.end(),0ll);
    ll ans=(k/sum)*n;
    ll p=sum*(k/sum);
    for(int i=0;i<n;i++)
    {
        p+=a[i];
        ans++;
        if(p>k)break;
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