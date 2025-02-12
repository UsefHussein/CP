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
vector<ll>a;set<pair<ll,ll>>st;int n;
void Suii() {
    ll n;
    cin >> n;
    auto it = st.lower_bound({n,0});
    if (it->F == n) {
        cout << it->S+1;
    } else cout << it->S;
    cout << enl;
}
void Fast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void File() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main() {
    Fast();
    File();
    ll op=2,l=4,r=1;
    while(op<=1e10+5)
    {
        st.insert({op,sz(st)});
        op+=(l+r);
        l+=2,r++;
    }
    //cout<<sz(st)<<enl;
    //for(auto i:st)cout<<i.F<< " ";
    int T_C =1;
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}