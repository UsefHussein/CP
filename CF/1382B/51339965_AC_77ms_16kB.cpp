#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double  dd;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
void Suii()
{
     int n;
     cin>>n;
     vector<ll>a(n);
     for(int i=0;i<n;i++)cin>>a[i];
     for(int i=0;i<n;i++)
     {
         if(a[i]>1)
         {
             if(i&1)
             {
                 cout<<"Second"<<enl;
                 return;
             }
             else
             {
                 cout<<"First"<<enl;
                 return;
             }
         }
     }
     if(!(n&1))cout<<"Second"<<enl;
     else cout<<"First"<<enl;

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