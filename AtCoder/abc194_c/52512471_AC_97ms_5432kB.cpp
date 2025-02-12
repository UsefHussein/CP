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
ll GCD(ll a, ll b) {
    return b == 0 ? a : GCD(b, a % b);
}
void Suii()
{
   int n;
   cin>>n;
   vector<ll>a(n),mpp(201),mpm(201);
   for(int i=0;i<n;i++)cin >> a[i];
   sort(all(a));
   ll ans=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<=200;j++)
       {
           ll k=a[i]-j;
           k*=k;
           ans+=k*mpp[j];
           k=a[i]+j;
           k*=k;
           ans+=k*mpm[j];
       }
       if(a[i]>=0)mpp[a[i]]++;
       else mpm[-a[i]]++;
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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}