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
     int n;cin>>n;
     vector<vector<ll>>a(n);
     set<ll>st;
     for(int i=0;i<n;i++)
     {
         int k;cin>>k;
         while(k--)
         {
             ll j;cin>>j;
             a[i].push_back(j);
             st.insert(j);
         }
     }
     ll ans=0,ans2=0,lp=0;
     for(auto i:a)
     {
         int m=0;
         for(int j=0;j<sz(i)-1;j++)
         {
             auto it=st.lower_bound(i[j]);
             it++;
             if(it==st.end()) ans++,m++;
             else if(*it!=i[j+1])ans++,m++;
         }
         m++;
         ans2+=m;
     }
     ans2--;
     cout<<ans<<" "<<ans2;


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
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}