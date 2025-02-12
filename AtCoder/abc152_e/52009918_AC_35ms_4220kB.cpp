#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int Mod=1e9+7,N=1e6+5;
map<ll,ll>mp;
void primeFactors(ll num)
{
    ll n=num;
    for(ll i=2;i*i<=n;i++){
        ll cnt=0;
        while(!(num%i)){
            num/=i;
            cnt++;
        }
        if(cnt)mp[i]=max(cnt,mp[i]);
    }
    if(num>1)mp[num]=max(1ll,mp[num]);
}
ll poow(ll x,ll y,ll mod)
{
    ll ans{1};
    while(y)
    {
        if(y&1)ans*=(x%mod);
        ans%=mod;
        x*=(x%mod);
        x%=mod;
        y/=2;
    }
    return (ans%mod);
}
void Suii() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        primeFactors(a[i]);
    }
    ll sum=1,ans=0;
    for (auto [i,j]:mp)
    {
        ll op= poow(i,j,Mod);
        sum*=op;
        sum%=Mod;
    }
    for (int i = 0; i < n; i++)
    {
        ll op= poow(a[i],Mod-2,Mod);
        ans+=(op*sum)%Mod;
        ans%=Mod;
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
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}