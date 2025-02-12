#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int Mod=1e9+7,N=1e6+5;
void Suii()
{
    int n;
    cin >> n;
    vector<ll> a(n),pr(n),su(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll pre=0,ans=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>pre)pre++;
        else pre=a[i];
        pr[i]=pre;
    }pre=0;
    for (int i = n-1; i >=0; i--)
    {
        if(a[i]>pre)pre++;
        else pre=a[i];
        ans=max(ans,min(pre,pr[i]));
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