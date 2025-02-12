#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double  dd;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
const ll MOD=1e9+7;
void Suii()
{
    int n;cin>>n;
    vector<ll>a(n);ll sum=0;
    for(int i=0;i<n;i++)cin>>a[i],sum+=a[i];
    sort(all(a));
    int q;cin>>q;
    while(q--)
    {
        ll x,y;cin>>x>>y;
        ll l=0,r=n-1,mid,mi=a[0],ma=a.back();
        while(l<=r)
        {
            mid=(l+r)/2;
            if(a[mid]<=x)
            {
                mi=a[mid];
                l=mid+1;
            }
            else r=mid-1;
        }
        l=0,r=n-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(a[mid]>=x)
            {
                ma=a[mid];
                r=mid-1;
            }
            else l=mid+1;
        }
        ll ans=min(max((y-(sum-mi)),0ll)+max(x-mi,0ll),
                   max((y-(sum-ma)),0ll)+max(x-ma,0ll));
        cout<<ans<<enl;
    }
}
void Fast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void File()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main() {
    Fast();
    File();
    int T_C =1;
   // cin >> T_C;
    while (T_C--)Suii();
    return 0;
}