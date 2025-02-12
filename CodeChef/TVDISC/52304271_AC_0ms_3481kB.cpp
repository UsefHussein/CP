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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll k=a-c,t=b-d;
    if(k<t)cout<<"First";
    else if(t<k)cout<<"Second";
    else cout<<"Any";
    cout<<enl;
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
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}