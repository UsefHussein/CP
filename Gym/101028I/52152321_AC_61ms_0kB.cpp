#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
bool Valid(vector<ll>&a,ll mid,ll k)
{
    ll cnt=a[0],l=1;
    for(int i=1;i<sz(a);i++)
    {
        if(a[i]-cnt+1>mid)
        {
            l++;
            cnt=a[i];
        }
    }
    return (l<=k);
}
void Suii()
{
    int n,k;cin>>n>>k;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll l=1,r=1e14,ans=1e18;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(Valid(a,mid,k))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
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
int32_t main()
{
    F_F();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T_C =1;
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}