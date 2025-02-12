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
vector<ll>I;
void GEN_I_I_I()
{
    for(ll i=2;i<=1e6;i++)
        I.push_back(1ll*(i*i*i));
}
ll Num_of_I_I_I(ll k)
{
    ll ans=0;
    for(int i=0;i<sz(I);i++)
    {
        ans+=k/I[i];
        if(I[i]>k)break;
    }
    return ans;
}
void Suii()
{
      ll n;cin>>n;
      ll l=0,r=1e16,mid,mn=1e18;
      while(l<=r)
      {
          mid=(l+r)/2;
          if(Num_of_I_I_I(mid)>=n)
          {
              mn = mid;
              r = mid - 1;
          }
          else l=mid+1;
      }
      if(Num_of_I_I_I(mn)==n)cout<<mn;
      else cout<<-1;
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
    int T_C =1;GEN_I_I_I();
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}