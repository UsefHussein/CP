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
void Suii()
{
    ll n;cin>>n;
    cout<<n*2;
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