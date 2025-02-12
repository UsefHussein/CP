#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e2+1,Mod=1e8;
void Suii()
{
    ll a,b,c;
    cin>>a>>b>>c;
    vector<ll>v={a,b,c};
    sort(all(v));
    ll op=v[0]+v[1],k=v[2]/4;
    if(v[2]%4==0&&(k*2)+k==op)cout<<"YA";
    else cout<<"TIDAK";

}
void F_F()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

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