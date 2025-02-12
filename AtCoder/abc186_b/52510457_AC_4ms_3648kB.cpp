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
const int N=5e3+2,Mod=1e9+7;
const ll NN = -1000000000000 ;
void Suii()
{
   int a,b;
   cin>>a>>b;
   set<ll>st;
   ll aa[a][b];
   for(int i=0;i<a;i++)
   {
       for(int j=0;j<b;j++)
       {
           cin>>aa[i][j];
           st.insert(aa[i][j]);
       }
   }
   ll mx=0;
   for(auto p:st)
   {
       ll sum=0;
       for (int i = 0; i < a; i++) {
           for (int j = 0; j < b; j++) {
                sum+=aa[i][j]-p;
           }
       }
       mx=max(mx,sum);
   }
   cout<<mx;
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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T_C =1;
    // cin >> T_C;
    while (T_C--)Suii();
    return 0;
}