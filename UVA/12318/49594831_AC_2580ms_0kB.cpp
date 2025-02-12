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
void Suii()
{

    while(1) {
        int n, m;
        cin >> n >> m;
        if(!n&&!m)break;
        set<ll> st;
        int k;
        cin >> k;
        vector<ll> a(k + 1);
        for (int i = 0; i <= k; i++)cin >> a[i];
        for (int i = 0; i <= m; i++) {
            ll h = 0;
            for (int j = 0; j <= k; j++) {
                h += a[j] * poow(i, j, (n + 1));
            }
            st.insert(h % (n + 1));
        }
        cout << sz(st) << enl;
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