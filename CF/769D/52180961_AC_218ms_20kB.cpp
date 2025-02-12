#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e4+2;
ll GetBit(ll n,int i)
{
    return (n>>i)&1ll;
}
void Suii()
{
   int n,x;cin>>n>>x;
   vector<ll>a(n),mp(N);
    ll ans=0;
   for(int i=0;i<n;i++)
   {
       cin >> a[i];
       ans+=mp[a[i]];
       mp[a[i]]++;
   }
   if(!x)return void(cout<<ans);
   else ans=0;
   for(int i=0;i<=N;i++)
   {
       for(int j=i;j<=N;j++)
       {
           ll D=__builtin_popcount(i^j);
           if(D==x)ans+=mp[i]*mp[j];
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