#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double  dd;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
int n,m,bo,ind=0;
const int N=505;
char a[N][N];
int Vis[N][N];
string h="snuke";
bool valid(int x,int y)
{
    return x>=0&&x<n&&y>=0&&y<m&&!Vis[x][y];
}
void Rec(int i,int j)
{
    if(i==n-1&&j==m-1&&a[i][j]==h[ind%5])
    {
        bo=1;
        return;
    }
    if(!valid(i,j)||a[i][j]!=h[ind%5])return;
    //cout<<a[i][j]<<" "<<ind<<" "<<i<<" "<<j<<enl;
    ind++;
    Vis[i][j]=1;
    Rec(i-1,j);
    Rec(i,j-1);
    Rec(i+1,j);
    Rec(i,j+1);
    ind--;
    //Vis[i][j]=0;
}
void Suii()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    Rec(0,0);
    if(bo)cout<<"Yes";
    else cout<<"No";
}
void Fast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void File()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int32_t main()
{
    Fast();
    File();
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}