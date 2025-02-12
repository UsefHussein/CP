#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
const int N=2e2+2,Mod=1e9+7;
const ll NN = -1000000000000 ;
int n,m,k;
ll a[N][N];
ll dp[N][N][500];
ll Back(int i,int j,int cnt)
{
    if(i>=n||j>=m||i<0||j<0)return -1e18;
    if(i==n-1&&j==m-1)return 0;
    ll &ret=dp[i][j][cnt];
    if(~ret)return ret;
    ret=-1e18;
    if(cnt&1)
    {
        ret=max(ret, Back(i+k,j+1,cnt+1)+a[i+k][j+1]*3);
        ret=max(ret, Back(i+1,j+k,cnt+1)+a[i+1][j+k]*3);
    }
    else
    {
        ret=max(ret, Back(i+k,j+1,cnt+1)+a[i+k][j+1]);
        ret=max(ret, Back(i+1,j+k,cnt+1)+a[i+1][j+k]);
    }
    return ret;
}
void Suii()
{
   cin>>n>>m>>k;
   for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
   ::memset(dp,-1,sizeof dp);
   ll ans=Back(0,0,0);
   cout<<(ans<0?-1:ans);
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