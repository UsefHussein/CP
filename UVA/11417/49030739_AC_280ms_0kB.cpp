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
ll GCD(ll a, ll b) {
    return b == 0 ? a : GCD(b, a % b);
}
int LCM(int a, int b) {
    return a / GCD(a, b) * b;
}
void Suii()
{
        ll n;
        while(cin>>n) {
            if (!n)return;
            ll G = 0;
            for (int i = 1; i < n; i++)
                for (int j = i + 1; j <= n; j++) G += GCD(i, j);
            cout << G << enl;
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