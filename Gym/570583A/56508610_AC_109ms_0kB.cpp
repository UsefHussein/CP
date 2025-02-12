#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

void $olve()
{
    ll a,b,c,n;
    cin>>a>>b>>c>>n;
    ll l=0,r=c,ans=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        if(mid*100<=n)
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    n-=ans*100;
    l=0,r=b,ans=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        if(mid*10<=n)
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    n-=ans*10;
    if(n-a<=0)cout<<"YES";
    else cout<<"NO";
    cout<<enl;
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
    cin>>T;
    while(T--)$olve();
    return 0;
}