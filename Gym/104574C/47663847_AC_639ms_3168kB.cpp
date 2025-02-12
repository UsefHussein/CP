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
    vector<dd>a(n),b(n);
    vector<pair<dd,ll>>vp(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        vp[i]={a[i]/b[i],i+1};
    }
    sort(all(vp));
    ll r=n-1,o=3;
    while(o--)cout<<vp[r--].second<<enl;
}
int main() {
    fffffffast();
    fffffffile();
    int t=1;//cin>>t;
    while(t--)sol();
    return 0;
}