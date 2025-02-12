#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double  dd;
#define enl "\n"
#define F first
//#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
void Suii()
{
   string s;
   cin>>s;
   ll R=0,P=0,S=0;
   for(auto i:s)
   {
       if(i=='P')P++;
       if(i=='S')S++;
       if(i=='R')R++;
   }
   vector<ll>a={P,S,R};
   sort(rall(a));
   if(a[0]==P)
   {
       for(int i=0;i<sz(s);i++)cout<<"S";
   }
   else if(a[0]==S)
   {
        for(int i=0;i<sz(s);i++)cout<<"R";
   }
   else if(a[0]==R)
   {
        for(int i=0;i<sz(s);i++)cout<<"P";
   }
    cout<<enl;

}
void Fast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void File()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int32_t main()
{
    Fast();
    File();
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}