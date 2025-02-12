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
const int N=5e3+2,Mod=1e9+7;
const ll NN = -1000000000000 ;
ll GCD(ll a, ll b) {
    return b == 0 ? a : GCD(b, a % b);
}
void Suii()
{
    ll n,m;
    cin>>n>>m;
    ll k=GCD(n,m);
    if(k==1)cout<<m<< " "<<n;
    else if(n==m)cout<<1<< " "<<1;
    else cout<<m/k<<" "<<n/k;
    cout<<enl;
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