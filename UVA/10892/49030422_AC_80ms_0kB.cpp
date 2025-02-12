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
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int lccm(int a, int b) {
    return a / gcd(a, b) * b;
}
vector<ll> divisors(ll num)
{
    vector<ll>divisor;
    for (ll i = 1; i * i <= num; i++) {
        if (!(num % i)) {
            divisor.push_back(i);
            ll x = num / i;
            if (x != i) {
                divisor.push_back(x);
            }
        }
    }
    return divisor;
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
void Suii()
{
    ll cnt = 0;
    while(1) {
        ll n;
        cin >> n;
        if(!n)return;
        vector<ll>divisor= divisors(n);
        sort(all(divisor));
        for (ll i: divisor)
            for (ll j: divisor) {
                if (lccm(i, j) == n && i > j)cnt++;
                if(j>=i)break;
            }
        cout << n << " " << cnt + 1 << enl;
        cnt=0;
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