#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e4+5;
ll dp[N][21][21];
int n,x;
vector<ll>a;
ll Dp(int l,int j,int c)
{
    int r=n-l-1-j+c;
    if(l>=r)return 0;
    if(j+c>x)return 1e18;
    ll &ret=dp[l][j][c];
    if(~ret)return ret;
    ret=1e18;
    if(a[l]==a[r])ret=min(ret,Dp(l+1,j,c));
    ret=min(ret,Dp(l,j+1,c)+1);
    ret=min(ret,Dp(l+1,j,c+1)+1);
    return ret;
}
void Suii()
{
    int t;cin>>t;
    for(int j=1;j<=t;j++)
    {
        cin >> n >> x;
        a.resize(n);
        for (int i = 0; i < n; i++)cin >> a[i];
        ::memset(dp, -1, sizeof dp);
        //Case 1:
        ll ans= Dp(0, 0, 0);
        cout<<"Case "<<j<<": ";
        if(!ans)cout<<"Too easy";
        else if(ans>x)cout<<"Too difficult";
        else cout<<ans;
        cout<<enl;
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