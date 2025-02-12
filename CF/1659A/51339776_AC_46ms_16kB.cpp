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
     ll n,r,b;
     cin>>n>>r>>b;
     string s="";
     vector<ll>st;
     while(1)
     {
         s+='R';
         s+='B';
         b--,r--;
         st.push_back(sz(s)-2);
         if(!b)break;
     }
     st.push_back(sz(s));
     if(r)
     {
         s+='R';
         r--;
     }
     //cout<<s<<enl;
     ll op=0;
     while(1)
     {
         if(!r)break;
         ll op=0;
         for(int i=0;i<sz(st);i++)
         {
             st[i]+=op;
             s.insert(st[i],1,'R');
            // cout<<s<<" "<<st[i]<<enl;
             r--;op++;
            //st[i]+=op;
             if(!r)break;
         }
         //cout<<enl;
     }
     cout<<s<<enl;

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