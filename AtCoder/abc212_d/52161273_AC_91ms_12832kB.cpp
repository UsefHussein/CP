#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
void Suii()
{
    multiset<ll>st;
    ll plus=0;
    int n;cin>>n;
    while(n--)
    {
        int t;cin>>t;
        if(t==3)
        {
            auto it=st.begin();
            cout<<*it+plus<<enl;
            st.erase(it);
        }
        else
        {
            ll k;cin>>k;
            if(t==2)plus+=k;
            else
            {
                st.insert(k-plus);
            }
        }
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