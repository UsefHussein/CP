#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int Mod=1e9+7,N=1e6+5;
void Suii() {
//   string s;cin>>s;
//   string h;cin>>h;
//   ll ans=0;
//   for(int i=0;i<sz(s);i++)
//   {
//       for(int j=0;j<sz(s);j++)
//       {
//           string k="";
//           for(int c=i;c<=j;c++)k+=s[c];
//           if(k==h)ans++;
//       }
//   }
//   cout<<ans;
     int n,q;cin>>n>>q;
     vector<ll>a(n);
     for(int i=0;i<n;i++)cin>>a[i];
     sort(all(a));
     while(q--)
     {
         ll v;cin>>v;
         int l=0,r=n-1,ind=0;
         while(l<=r)
         {
             int mid=(l+r)/2;
             if(a[mid]<=v)
             {
                 ind=mid+1;
                 l=mid+1;
             }
             else r=mid-1;
         }
         ll op=n-ind;
         if(v==a[ind-1])cout<<"0";
         else if(op&1)cout<<"NEGATIVE";
         else cout<<"POSITIVE";
         cout<<enl;
     }
}
void F_F()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int32_t main()
{
    F_F();
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}