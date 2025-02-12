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
ll poow(ll x,ll y)
{
    ll ans{1};
    while(y)
    {
        if(y&1)ans*=(x);
        x*=(x);
        y/=2;
    }
    return (ans);
}
const ll MOD=1e9+7;
void Suii()
{
    ll n;cin>>n;
    if(n&1)cout<<-1<<enl;
    else cout<<1<<" "<<n/2<<enl;
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
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}