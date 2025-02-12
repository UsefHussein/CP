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
vector<string>allsub(string s)
{
    vector<string>h;
    for(int i=0;i<sz(s);i++)
    {
        for(int j=i;j<sz(s);j++)
        {
            string k="";
            for(int c=i;c<=j;c++)k+=s[c];
            h.push_back(k);
        }
    }
    return h;
}
void Suii()
{
     string s,h;cin>>s>>h;
     vector<string>ss= allsub(s);
     vector<string>hh= allsub(h);
     ll mn=1e18;
     for(auto i:ss)
     {
         for(auto j:hh)
         {
             if(i==j)
             {
                 ll op=sz(s)-sz(i);
                 op+=sz(h)-sz(j);
                 mn=min(mn,op);
             }
         }
     }
     if(mn==1e18)mn=sz(s)+sz(h);
     cout<<mn<<enl;
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