#include <bits/stdc++.h>
#include <ext/rope>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef double dd;
#define enl "\n"
#define sz(x)  ll(x.size())
#define F first
#define S second
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
void Fffffffast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void Fffffffile() {
    //freopen("median.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
void sol() {
    int n,m;cin>>n>>m;
    vector<ll>a(m);   unordered_map<ll,ll>mp;
    for(int i=0;i<m;i++)cin>>a[i];
    set<pair<ll,ll>>st;
    st.insert({0,n});
    set<ll>Dif,Num;
    Num.insert(0),Num.insert(n);
    Dif.insert(n);mp[n]++;
    ll Mn=LLONG_MAX;
    for(int i=0;i<m;i++)
    {pair<ll,ll>p;
       auto it=Num.lower_bound(a[i]);
       p.S=*it;
       it--;
       p.F=*it;
       st.erase(p);mp[(p.S)-(p.F)]--;
       // cout<<p.first<<" "<<p.S<<enl;
       if(!mp[(p.S)-(p.F)])
       {

           //cout<<"Af"<<enl;
           Dif.erase((p.S)-(p.F));
           mp.erase((p.S)-(p.F));
       }
        Num.insert(a[i]);
        st.insert({p.F,a[i]});Dif.insert(a[i]-(p.F));mp[a[i]-(p.F)]++;
        st.insert({a[i],p.S});Dif.insert((p.S)-a[i]);mp[(p.S)-a[i]]++;
        auto Ans=Dif.end();
        Ans--;
        cout<<*Ans<<" ";
    }
}
int main() {
    Fffffffast();
    Fffffffile();
    int T_C= 1;//cin>>T_C;
    while (T_C--)sol();
    return 0;
}