#include <bits/stdc++.h>
#include <ext/rope>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef double dd;
#define enl "\n"
#define sz(x)  ll(x.size())
#define F first
#define S second
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
void Fffffffast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void Fffffffile() {
    //freopen("median.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
void sol() {
    int n;cin>>n;
    string s;cin>>s;
    ll op=count(all(s),'0');
    if(op&1&& op>1)cout<<"ALICE"<<enl;
    else cout<<"BOB"<<enl;
}
int main() {
    Fffffffast();
    Fffffffile();
    int T_C= 1;cin>>T_C;
    while (T_C--)sol();
    return 0;
}