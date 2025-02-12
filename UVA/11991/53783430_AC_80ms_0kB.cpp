#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
const int N=1e6+5,Mod=1e9+7;
vector<ll>a[N];
void Solve()
{
    int n,m;
    while(cin>>n>>m)
    {
        int mx=-1e9;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[x].push_back(i + 1);
            mx=max(mx,x);
        }
        while (m--) {
            int v, k;
            cin >> k >> v;
            int ans = 0;
            if (sz(a[v]) >= k)ans = a[v][k - 1];
            cout << ans << enl;
        }
        for(int i=1;i<=mx;i++)a[i].clear();
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
signed main()
{
    F_F();
    int T = 1;
    //cin>>T;
    while(T--) Solve();
    return 0;
}