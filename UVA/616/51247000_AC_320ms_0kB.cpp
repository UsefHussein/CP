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

void Suii()
{
    ll n;
    while(cin>>n) {
        if (n <0)return;
        ll a = 1, b = 0, c = 0, d, l = 0, mx = 0;
        n--;
        vector<ll> v;
        for (int i = 1; i * i < n; i++) {
            if (n % i == 0) {
                v.push_back(i);
                if (n / i != i)v.push_back(n / i);
            }
        }
        sort(all(v));
        for (int i = 1; i < v.size() ; i++) {
            bool ch = 1;
            b = n;
            c = 0;
            a = 0;
            l = 0;
            while (ch) {
                d = b / v[i];
                b -= d;
                c++;
                if (c == v[i] && b % v[i] == 0) {
                    ch = 0;
                    l = v[i];
                }
                if (b % v[i] != 1)ch = 0;
                b--;
                a++;
            }
            mx = max(mx, l);
        }
        if (mx)cout << n + 1 << " coconuts, " << mx << " people and 1 monkey\n";
        else cout << n + 1 << " coconuts, no solution\n";
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
int32_t main()
{
    Fast();
    File();
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}