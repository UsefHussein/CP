#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e4+2;
int n,k;
vector<ll>a;
ll Dp(int i, int j,int cnt)
{
    if(j<=i)return cnt;
    if(cnt>k)return 1e18;
    ll ret=1e18;
    if(a[i]==a[j])ret=Dp(i+1,j-1,cnt);
    else
    {
        ret = min(ret, Dp(i + 1, j, cnt + 1));
        ret = min(ret, Dp(i, j - 1, cnt + 1));
    }
    return ret;
}
void Suii()
{
    int t;cin>>t;
    for(int j=1;j<=t;j++)
    {
        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; i++)cin >> a[i];
        ll ans = Dp(0, n - 1,0);
        cout<<"Case "<<j<<": ";
        if (!ans)cout <<"Too easy";
        else if(ans>k)cout <<"Too difficult";
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