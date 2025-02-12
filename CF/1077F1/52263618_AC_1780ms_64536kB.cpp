#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define enl '\n'
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, v) for(int i=0;i<sz(v);++i)
#define lp(i, n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define MP make_pair

using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector< vi > vvi;
typedef vector< vd > vvd;
typedef vector<string> vs;
const int N=2e2+2;
ll dp[N][N][N];
int n,k;
vector<ll>a;
ll Dp(int i,int x,int last)
{
    if(i==n)return !x&&i-last<=k?0:-1e18;
    if(i-last>k||x<0)return -1e18;
    ll &ret=dp[i][x][last];
    if(~ret)return ret;
    ret=-1e18;
    ret=max(ret,Dp(i+1,x-1,i)+a[i]);
    ret=max(ret,Dp(i+1,x,last));
    return ret;
}
void Suii()
{
    int x;
    cin>>n>>k>>x;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll ans=-1;
    for(int i=0;i<k;i++)
    {
        ::memset(dp, -1, sizeof(dp));
        ans =max(ans, Dp(i+1, x-1, i)+a[i]);
    }
    cout<<ans;
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
