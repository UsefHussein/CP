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
    ll n;cin>>n;
    vector<ll>a(n),b(n);map<ll,ll>mp;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)
    {
        if(!b[i]&&a[i])
        {
            cout<<"NO"<<enl;
            return;
        }
    }
    if((a[n-1]!=b[n-1])||(a[0]!=b[0]))cout<<"NO";
    else if(!count(all(a),1)&&count(all(b),1))cout<<"NO";
    else cout<<"YES";
    cout<<enl;
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