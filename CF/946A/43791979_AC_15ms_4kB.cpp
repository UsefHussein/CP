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
bool pl(string s)
{
    string h=s;
    reverse(all(s));
    if(s==h)return 1;
    else return 0;
}
int main()
{
    fffffffast();
    fffffffile();
   int n;
   cin>>n;
   vector<ll>a(n);
    ll sum=0,sum2=0;
   for(auto i:a)
   {
       cin>>i;
       if(i>0)sum+=i;
       else sum2+=i;
   }
   cout<<sum-sum2;
    return 0;

}