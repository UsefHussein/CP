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
const ll N=105;
int a[N][N];
void Suii()
{
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                    cin>>a[i][j];

        for(int i=1;i<=n;i++)
        {
            for (int j=1; j <= m; j++)
            {
               if((i+j)&1&&a[i][j]&1)a[i][j]++;
               if(!((i+j)&1)&& a[i][j]%2==0)a[i][j]++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int y=1;y<=m;y++)
            {
                cout<<a[i][y]<<" ";
            }
            cout<<enl;
        }
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
int main() {
    Fast();
    File();
    int T_C =1;
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}