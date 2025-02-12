#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
string s;
void Suii()
{
    int n;cin>>n;
    vector<ll>a(n);map<ll,ll>mp;
    for(int i=0;i<n;i++)cin>>a[i],mp[a[i]]=1;
    sort(all(a));
    ll ans=0,k= accumulate(all(a),0ll)+1;
    for(int i=0;i<n;i++)
    {
        if(a[i]>ans+1)
        {
            k=ans+1;
            break;
        }
        ans+=a[i];
    }
//    for(int i=0;i<(1<<n);i++)
//    {
//        ll sum=0;
//        for(int j=0;j<n;j++)
//        {
//            if(i&(1<<j))sum+=a[j];
//        }
//        mp[sum]++;
//    }
//    ll mn=0;
//    while(1)
//    {
//        if(!mp.count(mn))break;
//        mn++;
//    }
    cout<<k;
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
int32_t main()
{
    F_F();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}