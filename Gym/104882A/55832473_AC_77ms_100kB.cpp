#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int Mod=1e9+7;

void $olve()
{
    ll n,p;
    cin>>n>>p;
    ll poow=pow(10,p);
    ll l=0,r=poow,ans1l=-1,ans1r=-1,ans2l=-1,ans2r=-1;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        ll op=n-(-mid);
        if(op>=-poow&&op<=poow)
        {
            ans1l=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    l=0,r=poow;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        ll op=n-(-mid);
        if(op>=-poow&&op<=poow)
        {
            ans1r=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    l=0,r=poow;;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        ll op=n-(mid);
        if(op>=-poow&&op<=poow)
        {
            ans2l=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    l=0,r=poow;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        ll op=n-(mid);
        if(op>=-poow&&op<=poow)
        {
            ans2r=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    if(~ans1r&&~ans2r)
    {
        cout<<ans1r+ans2r+1<<enl;
    }
    else if(~ans1r)
    {
        cout<<ans1r-ans1l+1<<enl;
    }
    else if(~ans2r)
    {
        cout<<ans2r-ans2l+1<<enl;
    }
    else if(~ans1l)
    {
        cout<<poow-ans1l+1<<enl;
    }
    else if(~ans2l)
    {
        cout<<poow-ans2l+1<<enl;
    }
    else cout<<0;
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