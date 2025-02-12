#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
void Suii() {
   int n;cin>>n;
   string s,m;cin>>s>>m;
   vector<ll>ans;
   for(int i=n-1;i>=0;i--)
   {
       if(s[i]!=m[i])
       {
           if(s[0]==m[i])
           {
               s[0]=='1'?s[0]='0':s[0]='1';
               ans.push_back(0);
           }
           ans.push_back(i);
           for(int j=0;j<=i;j++)s[j]=='1'?s[j]='0':s[j]='1';
           reverse(s.begin(),s.begin()+i+1);
       }
   }
   cout<<sz(ans)<< " ";
   for(auto i:ans)cout<<i+1<<" ";
   cout<<enl;
}
void Fffffffast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void Fffffffile() {
    //freopen("median.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
int main() {
    Fffffffast();
    Fffffffile();
    int T_C = 1;
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}