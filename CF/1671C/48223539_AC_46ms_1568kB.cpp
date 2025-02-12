#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
void Suii() {
    ll n,m;cin>>n>>m;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));
    ll ans=0,sum=0;
    for(int i=0;i<n;i++) {
        sum+=a[i];
        if(m>=sum)
        {
            ans+=(m-sum)/(i+1);
            ans++;
        }
    }
    cout<<ans<<enl;
}
void Fffffffast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void Fffffffile() {
    //freopen("median.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
int main() {
    Fffffffast();
    Fffffffile();
    int T_C = 1;
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}