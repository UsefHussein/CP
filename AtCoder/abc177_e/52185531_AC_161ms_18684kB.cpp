#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e3+2;
set<ll> primeFactors(ll num){
    ll n=num;set<ll>st;
    for(ll i=2;i*i<=n;i++){
        int cnt=0;
        while(!(num%i)){
            num/=i;
            cnt++;
        }
        if(cnt)st.insert(i);
    }
    if(num>1)st.insert(num);
    return st;
}
void Suii()
{
    int n;cin>>n;
    vector<ll>a(n),mp(1e6+1);
    for(int i=0;i<n;i++)cin>>a[i];
    ll gc=a[0];
    for(int i=1;i<n;i++)gc=gcd(gc,a[i]);
    if(gc!=1)return void(cout<<"not coprime");
    for(int i=0;i<n;i++)
    {
        set<ll>st= primeFactors(a[i]);
        for(auto j:st)
        {
            mp[j]++;
            if(mp[j]==2)return void(cout<<"setwise coprime");
        }
    }
    cout<<"pairwise coprime";
}
void F_F()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int32_t main()
{
    F_F();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}