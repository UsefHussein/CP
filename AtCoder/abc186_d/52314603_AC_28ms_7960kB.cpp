#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define rall(x)  x.rbegin(), x.rend()
void Suii()
{
    int n;cin>>n;
    vector<ll>a(n),pr(n),prr(n);
    for(int i=0;i<n;i++)cin >> a[i];
    ll sum= accumulate(rall(a),0ll);
    sort(rall(a));
    ll op=0,ans=0,sum2=0;
    for(int i=0;i<n-1;i++)
    {
        sum2+=a[i];
        op=(a[i]*(n-i-1))-(sum-sum2);
        ans+=op;
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