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
map<ll,ll>mp;
void primeFactors(ll num){
    ll n=num;
    for(ll i=2;i*i<=n;i++){
        int cnt=0;
        while(!(num%i)){
            num/=i;
            cnt++;
        }
        if(cnt)mp[i]+=cnt;
    }
    if(num>1)mp[num]++;
}
pair<ll,ll> Make_num(string s)
{
    ll cnt=0,num=0;
    for(auto i:s)
    {
        if(i=='!')
        {
            cnt++;
            continue;
        }
        num+=i-'0';
        num*=10;
    }
    return {num/10,cnt};
}
void Suii()
{
    int t;cin>>t;
    for(int u=1;u<=t;u++) {
        string s;
        cin >> s;
        vector<ll> a;
        ll cnt = Make_num(s).S, num = Make_num(s).F;
        unsigned long long sum = 1;
        for (ll i = num; i >= 2; i -= cnt) primeFactors(i);
        for (auto i: mp) {
            sum *= i.S + 1;
            if (sum > 1e18) {
                cout <<"Case "<<u<<": Infinity"<< enl;
                mp.clear();
                goto F;
            }
        }
        cout <<"Case "<<u<<": "<< sum << enl;
        F:;
        mp.clear();
    }
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
   // cin >> T_C;
    while (T_C--)Suii();
    return 0;
}