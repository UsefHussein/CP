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
       int n,k;cin>>n>>k;
       string s;cin>>s;
       string Vis=s;
       int ans=0,cc= count(all(s),'*');
       if(cc<=2)
       {
           cout<<cc<<enl;
           return;
       }
       for(int i=0;i<n;i++)
       {
           if(s[i]=='*')
           {
               int l=min((i+k),n-1);
               for(int j=i+1;j<=l;j++)
               {
                   if(s[j]=='*')i=j-1;
               }
               ans++;
               Vis[i]='T';
           }
       }
       for(int i=n-1;i>=0;i--)
       {
           if(s[i]=='*') {
               if (Vis[i] == '*') ans++;
               break;
           }
       }
       //cout<<Vis<<enl;
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