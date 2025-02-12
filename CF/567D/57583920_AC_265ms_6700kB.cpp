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
ll Howmany_ships(ll f,ll s,ll m)
{
    ll Valid=s-f-1;
    ll l=0,r=1e9,ans=0,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        ll op=(mid*m)+(mid-1);
        if(op<=Valid)
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
void Suii()
{
       int c,k,m;
       cin>>c>>k>>m;
       int n;cin>>n;
       ll rem=Howmany_ships(0,c+1,m);
       set<ll>st={0,c+1};
       for(int i=0;i<n;i++)
       {
           int v;
           cin>>v;
           auto se=st.lower_bound(v);
           auto fr=se;
           fr--;
           rem-=Howmany_ships(*fr,*se,m);
           rem+=Howmany_ships(v,*se,m)+Howmany_ships(*fr,v,m);
           if(rem<k)
           {
               cout<<i+1;
               return;
           }
           st.insert(v);
       }
       cout<<-1;
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