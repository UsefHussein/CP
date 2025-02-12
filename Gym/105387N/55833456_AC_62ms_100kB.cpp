#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long


void $olve()
{
    int n;
    cin>>n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        string ch;
        cin>>ch;
        if(ch=="?")v[i]=-1;
        else v[i]=stoi(ch);
    }
    ll l=0,r=1e18,ans=0;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        bool bo=0;
        for(int i=0;i<n;i++)
        {
            long  double p=(double)mid/(double)(i+1);
            ll op=round(p);
            if(v[i]!=-1&&op<v[i])bo=1;
        }
        if(!bo)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
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