#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double  dd;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
void Suii() {
    int n, a, b;
    cin >> n >> a >> b;
    set<ll> st;
    vector<ll> ansa, ansb{b} ;
    for (int i = 1; i <= n; i++) {
        if (i < b&&i!=a)st.insert(i);
    }
    for (auto i: st) {
        ansb.push_back(i);
        //cout<<i<<enl;
        if (sz(ansb) == (n / 2))break;
    }
    for (int i = 1; i <= n; i++) {
        if(!count(all(ansb),i))ansa.push_back(i);
    }
    ll mna=1e18,mxb=-1e18;
    for(auto i:ansa)mna=min(mna,i);
    for(auto i:ansb)mxb=max(mxb,i);
    if(mna!=a||mxb!=b||sz(ansb)!=(n/2)||sz(ansa)!=(n/2))
    {
        cout<<-1<<enl;
        return;
    }
    for(auto i:ansa)cout<<i<< " ";
    for(auto i:ansb)cout<<i<< " ";
    cout<<enl;
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
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}