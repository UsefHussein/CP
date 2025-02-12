#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define F first
#define S second
#define all(x)  x.begin(), x.end()
const ll Mod=1e9+7,N=1e12+5;
void Suii()
{
    int n,q;cin>>n>>q;
    string s;cin>>s;
    ll k=0;
    while(q--)
    {
        ll t,m;cin>>t>>m;
        if(t==2)
        {
            ll ind=(m-k-1);
            ind+=n;
            ind%=n;
            cout<<s[ind]<<enl;
        }
        else
        {
            k+=m;
            k%=n;
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
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}