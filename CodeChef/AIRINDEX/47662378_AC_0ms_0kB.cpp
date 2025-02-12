#include <bits/stdc++.h>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef double dd;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
void fffffffast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void fffffffile() {
    //freopen("median.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
void sol() {
   ll n;cin>>n;
   cout<<(n<100?"YES":"NO");
}
int main() {
    fffffffast();
    fffffffile();
    int t=1;//cin>>t;
    while(t--)sol();
    return 0;
}