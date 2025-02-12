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
    ll n;cin>>n;ll sum=0;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i],sum+=a[i];
    if(sum%2==0&&abs(*max_element(all(a))-sum)>=*max_element(all(a)))cout<<"YES";
    else cout<<"NO";
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