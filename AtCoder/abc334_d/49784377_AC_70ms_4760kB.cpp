#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
void Suii()
{
    ll n,q;cin>>n>>q;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));
    for(int i=1;i<n;i++)a[i]+=a[i-1];
    while(q--)
    {
        ll m;cin>>m;
        ll ans=0,l=0,r=n-1,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(a[mid]<=m)
            {
                ans=mid+1;
                l=mid+1;
            }
            else r=mid-1;
        }
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
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}