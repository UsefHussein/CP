#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
string s;
bool Valid(ll mid,ll n)
{
    ll cnt=0;
    for(int i=0;i<mid;i++)if(s[i]=='.')cnt++;
    if(cnt<=n)return 1;
    ll l=0,r=mid;
    while(r<sz(s))
    {
        if(s[l]=='.')cnt--;
        if(s[r]=='.')cnt++;
        if(cnt<=n)return 1;
        l++,r++;
    }
    return 0;
}
void Suii()
{
    cin>>s;
    int n;cin>>n;
    ll l=0,r=sz(s),ans=1e18;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(Valid(mid,n))
        {
            ans=mid;
            l=mid+1;

        }
        else r=mid-1;
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
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}