#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
vector<ll>v,a;

void $olve()
{
    int n,m;
    cin>>n>>m;
    a=v=vector<ll>(m);
    vector<pair<ll,ll>>pre(n+5,{2e9,2e9}),su(n+5,{2e9,2e9});
    for(int i=0;i<m;i++)cin>>a[i];
    for(int i=0;i<m;i++)
    {
        cin>>v[i];
        pre[a[i]-1]={v[i],a[i]-1};
        su[a[i]-1]={v[i],a[i]-1};
    }
    for(int i=1;i<n;i++)
    {
         if(pre[i].first>pre[i-1].first)
         {
             pre[i]=pre[i-1];
             pre[i].first++;
         }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(su[i].first>su[i+1].first)
        {
            su[i]=su[i+1];
            su[i].first++;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<min(pre[i].first,su[i].first)<<" ";
    }
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