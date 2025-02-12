#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e4+2;
ll dp[800][150][55];
ll Dp(int cnt,int i, int j,int c)
{
    if(i<0||j<0||c<0)return 1e18;
    if(!cnt)return 0;
    ll &ret=dp[i][j][c];
    if(~ret)return ret;
    ret=1e18;
    ret=min(ret, Dp(cnt-1,i+2,j,c-1)+1);
    ret=min(ret, Dp(cnt-1,i-3,j-1,c)+4);
    ret=min(ret, Dp(cnt-1,i+2,j-2,c)+2);
    ret=min(ret, Dp(cnt-1,i-8,j,c)+8);
    ret=min(ret, Dp(cnt-1,i-3,j+1,c-1)+4);
    return ret;
}
void Suii()
{
    int t;cin>>t;
    for(int i=1;i<=t;i++) {
        int a, n, nn, nnn;
        cin >> a >> n >> nn >> nnn;
        ::memset(dp, -1, sizeof dp);
        cout << Dp(a, n, nn, nnn)<<enl ;
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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}