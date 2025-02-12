#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int Mod=1e9+7,N=1e6+5;
string Convert_To_Base_x(ll n,ll m)
{
    vector<ll>a;
    if(char(m)>='A'&&char(m)<='Z')m-=55;
    ll c=0;
    while(n)
    {
        ll g=n%m;
        c++;
        a.push_back(g);
        n/=m;
    }
    string h="";
    for(int i=c-1; i>=0; i--)
    {
        if(a[i]>9)h+=char(a[i]+55);
        else h+=a[i]+'0';
    }
    return h;
}
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
     ll n;cin>>n;
     ll ans=0;
     for(int i=1;i<=n;i++)
     {
         ll Ni=i;
         string h= Convert_To_Base_x(Ni,8);
         bool bo=1;
         for(auto i:h)if(i=='7')bo=0;
         while(Ni)
         {
             if(Ni%10==7)
             {
                 bo=0;
                 break;
             }
             Ni/=10;
         }
         if(bo)ans++;
     }
     cout<<ans;
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