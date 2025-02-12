#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
map<pair<ll,ll>,ll>mp;
ll n,F,T;
vector<pair<ll,ll>>pp;
ll Dp(int i,ll C)
{
    if(i==n||C>=F)
    {
        if(C<F)return 1e18;
        return 0;
    }
    if(mp.count({i,C}))return mp[{i,C}];
    ll &ret=mp[{i,C}];
    ret=1e18;
    ret=min(ret, Dp(i+1,C+(T*pp[i].first))+pp[i].second);
    ret=min(ret, Dp(i+1,C));
    mp[{i,C}]=ret;
    return mp[{i,C}];
}
void Suii()
{
   cin>>n;
   pp.resize(n);
   for(int i=0;i<n;i++)cin>>pp[i].first>>pp[i].second;
   int q;cin>>q;
   for(int i=1;i<=q;i++)
   {
       ll a,b;cin>>a>>b;
       F=a,T=b;
       mp.clear();
       ll ans=Dp(0,0);
       //Case 1: 120000
       cout<<"Case "<<i<<": ";
       if(ans==1000000000000000000)cout<<"IMPOSSIBLE";
       else cout<<ans;
       cout<<enl;
   }
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