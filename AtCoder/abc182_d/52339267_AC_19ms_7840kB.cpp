#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
void Suii()
{
    int n;cin>>n;
    vector<ll>a(n),pr(n),prr(n);
    for(int i=0;i<n;i++)cin >> a[i];
    pr=a;
    for(int i=1;i<n;i++)pr[i]+=pr[i-1];
    prr=pr;
    for(int i=1;i<n;i++)prr[i]+=prr[i-1];
    ll ans=max(0ll,prr.back()),mx1=0;
    for(int i=0;i<n-1;i++)
    {
        mx1=max(mx1,pr[i]);
        ans=max(ans,prr[i]+mx1);
        ans=max(ans,prr[i]);
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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}