#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
// 1ll<<i متنساش ll
const int N=1e3+5;
ll dp[N][N];
string s,t;
ll Dp(int i,int j)
{
    if(i==sz(s)||j==sz(t))return 0;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    if(s[i]==t[j])return ret=Dp(i+1,j+1)+1;
    return ret=max(Dp(i+1,j),Dp(i,j+1));
}
void Suii()
{
    ll T=1;
    while(1)
    {
        getline(cin,s);
        getline(cin,t);
        if(T!=1)cout<<enl;
        //Case #1: you can visit at most 3 cities.
        if(s[0]=='#')break;
        memset(dp, -1, sizeof dp);
        cout <<"Case #"<<T++<<": you can visit at most "<<
        Dp(0, 0)<<" cities."
        ;
    }
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
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}