#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e2+1,Mod=1e8;
bool prime(ll x){
    if(x < 2)
        return false;

    for(ll i = 2 ; i*i <=x ;i++ ){
        if(x%i == 0)
            return false;
    }
    return true;
}
void Suii()
{
    int n;cin>>n;
    ll op=1;
    for(int i=2;i<=n;i++)op=lcm(op,i);
    cout<<op+1<<enl;
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