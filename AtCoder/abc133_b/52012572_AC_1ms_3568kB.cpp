#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int Mod=1e9+7,N=1e6+5;
void Suii() {
    int n, m;
    cin >> n >> m;
    ll a[n][m];
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> a[i][j];
    ll ans = 0;
    for (int v = 0; v < n; v++)
    {

        for (int i =v+1; i < n; i++)
        {
            ll sum=0;
            for (int j = 0; j < m; j++)
            {
                ll k=a[v][j]-a[i][j];
                sum+=k*k;
            }
            ll j=sqrt(sum);
            if(j*j==sum)ans++;
        }
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