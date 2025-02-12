#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
ll x,y,a,b;
bool VALid(int mid)
{
    return (x-a*mid)>=0&&(y-a*mid)>=0
    &&(x-a*mid)/(b-a)+(y-a*mid)/(b-a)>=mid;
}
void $olve()
{
    cin>>x>>y>>a>>b;
    if(a>b)swap(a,b);
    if(x>y)swap(x,y);
    if(a==b)
    {
        cout<<min(x,y)/a<<enl;
        return;
    }
    ll ans=0,l=0,r=2e9,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(VALid(mid))ans=mid,l=mid+1;
        else r=mid;
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
    cin>>T;
    while(T--)$olve();
    return 0;
}