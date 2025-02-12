#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
void Suii() {
   ll n,m;cin>>n>>m;ll ans=0,lk=n^m;
   ll l=0,r=1073741823,mid;
   while(l<=r)
   {
       mid=(l+r)/2;
       ll op=abs((mid^n)-(mid^m));
       if(op<=lk)
       {
           lk=op;
           r=mid-1;
           ans=mid;
       }
       else l=mid+1;
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