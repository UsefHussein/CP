#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
void Suii() {
   ll a,b,c,n;cin>>a>>b>>c>>n;
   ll sum=0;
    if((c*100)>=n)
    {
        ll o=n/100;
        n-=(o*100);
    }
    else n-=(c*100);
   // cout<<n<<enl;
    if((b*10)>=n)
    {
        ll op=n/10;
        n-=(op*10);
    }
    else n-=(b*10);
    //cout<<n<<enl;
    if(n<=a)cout<<"YES";
    else cout<<"NO";
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