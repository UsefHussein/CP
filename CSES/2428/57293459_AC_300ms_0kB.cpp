#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

void $olve()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int r=0,dis=0;
    ll ans=0;
    map<int,int> mp;
    for(int l=0;l<n;l++)
    {
        while(r<n)
        {
            if(!mp.count(a[r]))
            {
                if(dis==k)break;
                dis++;
            }
            mp[a[r]]++;
            if(dis<=k)ans+=r-l+1;
            else break;
            r++;
        }
        mp[a[l]]--;
        if(!mp[a[l]])
        {
            auto it=mp.find(a[l]);
            mp.erase(it);
            dis--;
        }
    }
    cout<<ans;
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
