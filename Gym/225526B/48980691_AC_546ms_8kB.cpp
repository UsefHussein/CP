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
void Suii() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    vector<vector<ll>> ans;
    for (int i = 0; i < n; i++) {
        vector<ll> v;
        int y;
        cin >> y;
        v.push_back(i);
        while (y--) {
            int k;
            cin >> k;
            v.push_back(k - 1);
        }
        ans.push_back(v);
    }
    ll mn = LLONG_MAX;
    for (int i = 0; i < (1 << n); i++)
    {
        map<ll, ll> mp;
        ll sum = 0;
        for (int j = 0; j < sz(ans); j++) 
        {
            if (i & (1 << j)) 
            {
                sum += a[ans[j][0]];
                for (int c = 0; c < sz(ans[j]); c++) 
                {
                    mp[a[ans[j][c]]]++;
                }
            }
        }
        bool bo = 1;
        for (int j = 0; j < n; j++) 
        {
            if (!mp.count(a[j])) 
            {
                bo = 0;
                break;
            }
        }
        if (bo && sz(mp))mn = min(mn, sum);
    }
    cout << mn;
}
void Fast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void File() {
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