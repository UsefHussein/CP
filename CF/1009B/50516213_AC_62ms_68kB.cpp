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
vector<ll>a;
int ind=-1;
ll calc(ll q,int fr,int se)
{
    ll ans=LLONG_MIN;
    for(int i=fr;i<=se;i++)
    {
        ll op=q*a[i];
        if(op>ans)
        {
            ans=op;
            ind=i;
        }
    }
    return ans;
}
ll calc2(ll q,int fr,int se)
{
    ll ans=LLONG_MIN;
    for(int i=fr;i<=se;i++)ans=max(ans,q*a[i]);
    return ans;
}
void Suii()
{
      string s;cin>>s;
      ll cnt0=0,cnt1=count(all(s),'1');
      int n=sz(s),ind=-1;
      for(int i=0;i<n;i++)
      {
          if(s[i]=='2')
          {
              ind=i;
              break;
          }
          if(s[i]=='0')cnt0++;
      }
      while(cnt0--)cout<<0;
      while(cnt1--)cout<<1;
      if(ind==-1)return;
      for(int i=ind;i<n;i++)if(s[i]!='1')cout<<s[i];

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
int main() {
    Fast();
    File();
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}