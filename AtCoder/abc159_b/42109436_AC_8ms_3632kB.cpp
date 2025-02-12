#include<bits/stdc++.h>
#include <set>
#include <map>
#define enl "\n"
typedef long long ll;
typedef double dd;
//set<int,greater<int>>d;
//priority_queue<ll,vector<ll>,greater<ll>>q;
#define all(x)  x.begin(), x.end()
using namespace std;
const ll r = 1e5 + 10;
bool pali(string s)
{
    string h=s;
    reverse(all(s));
    if(h==s)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    //cout<<fixed<<setprecision(6);
    //A->65  Z->90
    //a->97  z->122
   string s,d="",w="";
   cin>>s;
   int n=s.size();
   if(pali(s)==0)
   {
       cout<<"No";return 0;
   }
   for(int i=0;i<(n/2);i++)
   {

       d+=s[i];
   }
   for(int i=((n+2)/2);i<n;i++)
   {

       w+=s[i];
   }
  // cout<<d<<" " <<w<<enl;
   if(pali(d)==1&&pali(w)==1)
   {
       cout<<"Yes";
   }
   else
   {
       cout<<"No";
   }

    return 0;

}
