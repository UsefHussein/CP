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
const int N=2e2+2,Mod=1e9+7;
const ll NN = -1000000000000 ;
void Suii()
{
    int n,m;
    cin>>n>>m;
    vector<ll>a(n);
    multiset<ll>st;
    ll mn=-1e18;
    for(int i=0;i<n;i++)cin>>a[i];
    st.insert(a[0]);
    for(int i=1;i<n;i++)
    {
        ll op = abs(*st.begin() - a[i]);
        ll op2 = abs(*st.rbegin() - a[i]);
        mn = max({mn, op, op2});
        if(sz(st)>m)
        {
            ll k = i - m - 1;
            auto it = st.lower_bound(a[k]);
            st.erase(it);
        }
        st.insert(a[i]);
    }
    cout<<mn<<enl;

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
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}