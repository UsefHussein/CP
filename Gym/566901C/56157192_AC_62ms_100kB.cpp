#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=1e2;

void $olve()
{
    int n,m;
    cin>>n>>m;
    map<pair<int,int>,int>mp;
    for(int j=0;j<m;j++)
    {
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=1;i<n;i++)
        {
            pair<int,int> p={a[i],a[i-1]};
            if(p.first>p.second)swap(p.first,p.second);
            mp[p]=1;
        }
    }
    ll ans=0;
    for(int j=0;j<n;j++)
    {
        for(int i=j+1;i<n;i++)
        {
            if(!mp.count({j+1,i+1}))
            {
                ans++;
                mp[{j+1,i+1}]=1;
            }
        }
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