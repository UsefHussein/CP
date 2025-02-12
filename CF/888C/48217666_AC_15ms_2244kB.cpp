#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.rbegin(), x.rend()
void Suii() {
    vector<vector<ll>>mp(125,vector<ll>(1,0));
    string s;cin>>s;
    for(int i=0;i<sz(s);i++)mp[s[i]].push_back(i+1);
    for(int i='a';i<='z';i++)mp[i].push_back(sz(s)+1);
    ll ans=sz(s);
    for(int i='a';i<='z';i++)
    {
        ll mx=LLONG_MIN;
        for(int j=1;j<sz(mp[i]);j++)mx=max(mx,mp[i][j]-mp[i][j-1]);
        ans=min(ans,mx);
    }
    cout<<ans;
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
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}