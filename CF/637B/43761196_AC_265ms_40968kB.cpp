#include<bits/stdc++.h>
#define enl "\n"
typedef long long ll;
typedef double dd;
using namespace std;
#define sz(x)  x.size()
#define all(x)  x.begin(), x.end()
const ll r = 1e5 + 10;
void fffffffast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void fffffffile() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
int main()
{
    fffffffast();
    fffffffile();
    int t;
    cin>>t;
    vector<string>l,k;
    set<string>st;
    stack<string>a;
    while(t--)
    {
        string s;
        cin>>s;
        l.push_back(s);
    }
    reverse(all(l));
    map<string,ll>mp;
    for(int i=0;i<sz(l);i++)
    {
      if(mp[l[i]]==0)
      {
          mp[l[i]]++;
          a.push(l[i]);
      }
    }
    while(!a.empty())
    {
       k.push_back(a.top());
        a.pop();
    }
    reverse(all(k));
    for(auto &i:k)cout<<i<<enl;
     return 0;

}

