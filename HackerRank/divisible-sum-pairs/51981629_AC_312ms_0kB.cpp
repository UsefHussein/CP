#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()

void Suii() {
    int n,k;
    cin >> n>>k;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] %= k;
    }
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
        ll op = k - a[i];
        if(op==k)op=0;
        if(a[i]==op)sum += mp[op]-1;
        else sum += mp[op];
    }
    cout << sum;
}
void F_F()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
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