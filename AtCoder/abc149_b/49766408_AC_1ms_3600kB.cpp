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
ll poow(ll x,ll y,ll mod)
{
    ll ans{1};
    while(y)
    {
        if(y&1)ans*=(x%mod);
        ans%=mod;
        x*=(x%mod);
        x%=mod;
        y/=2;
    }
    return (ans%mod);
}
void Suii() {
    ll a, b, c;
    cin >> a >> b >> c;
    //cout<<a<<" "<<b<<" "<<c;
    if (c > a) {
        c -= a;
        a = 0;
    }
    else if (a>=c) {
        //cout<<"ad"<<enl;
        a-=c;
        c=0;
    }
    if (c > b) {
        c -= b;
        b= 0;
    }
    else if (b>=c)b-=c;
    cout<<a<<" "<<b;
}
void Fast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void File()
{
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