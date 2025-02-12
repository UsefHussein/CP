#include <bits/stdc++.h>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef double dd;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
void fffffffast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void fffffffile() {
    //freopen("median.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
void sol() {
   ll n,m;cin>>n>>m;
   ll cnt=0;
   for(int i=1;i<=5;i++)
   {
       m-=(n/2);
       cnt++;
       if(m<=0)break;
   }
  // cout<<m<<" "<<cnt<<" ";
   if(m>0)
   {
       while(1)
       {
           cnt++;
           m-=n;
           if(m<=0)break;
       }
   }
   cout<<cnt<<enl;
}
int main() {
    fffffffast();
    fffffffile();
    int t=1;cin>>t;
    while(t--)sol();
    return 0;
}