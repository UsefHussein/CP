#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1002,Mod=1e9+7;
int n,m,ans;
char a[N][N];
vector< vector< int > >dp;
bool Valid(int i,int j)
{
    if(j>=m||i>=n||a[i][j]=='#')return 0;
    return 1;
}
int Dp(int i,int j)
{
    if(i==n-1&&j==m-1)return 1;
    if(!Valid(i,j))return 0;
    int &ret=dp[i][j];
    if(~ret)return ret;
    return ret=(Dp(i+1,j)+Dp(i,j+1))%Mod;
}
void Suii()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
    dp.assign(N,vector<int>(N,-1));
    cout<<Dp(0,0)%Mod;

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