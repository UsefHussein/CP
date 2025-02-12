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
string s,ss;
bool Valid(int i)
{
    if(s[i]=='0'&&ss[i]=='0'&&
    (s[i+1]=='1'&&ss[i+1]=='1'))
    {
        return 1;
    }
    if(s[i+1]=='0'&&ss[i+1]=='0'&&
       (s[i]=='1'&&ss[i]=='1'))
    {
        return 1;
    }
    return 0;
}
void Suii()
{
      int n;cin>>n;
      cin>>s>>ss;
      ll ans=0;
      for(int i=0;i<n;i++)
      {
         if(Valid(i))
         {
             ans+=2;
             i++;
         }
         else if(s[i]=='1'&&ss[i]=='0')ans+=2;
         else if(s[i]=='0'&&ss[i]=='1')ans+=2;
         else if(s[i]!='1'&&ss[i]!='1')ans++;
      }
      cout<<ans<<enl;
    
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
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}