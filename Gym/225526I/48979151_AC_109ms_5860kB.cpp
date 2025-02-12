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
    ll n,m;cin>>n>>m;multiset<ll>st;
    vector<ll>a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i],st.insert(a[i]);
    for(int i=0;i<m;i++)cin>>b[i];
    sort(rall(b)),sort(rall(a));ll ans=0,r=0;
    for(int i=0;i<n;i++)
    {
        if(r==m)break;
        if(b[r]>=a[i])ans+=a[i],r++;
    }
    cout<<ans;
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
    int T_C =1;
//    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}