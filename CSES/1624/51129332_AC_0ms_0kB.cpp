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
int n,cnt;
vector<ll>Vis_Row;
vector<string>Chess;
vector<string>a;
set<vector<string>>ans;
bool Valid(int r,int c)
{
    for(int i=r,j=c;i<n&&j<n;i++,j++)
    {
        if(Chess[i][j]=='Q')return 0;
    }
    for(int i=r,j=c;i>=0&&j>=0;i--,j--)
    {
        if(Chess[i][j]=='Q')return 0;
    }
    for(int i=r,j=c;i<n&&j>=0;i++,j--)
    {
        if(Chess[i][j]=='Q')return 0;
    }
    for(int i=r,j=c;i>=0&&j<n;i--,j++)
    {
        if(Chess[i][j]=='Q')return 0;
    }
    return true;
}
void N_q(int N,int j)
{
    if (!N)
    {
        bool bo=0;
        ans.insert(Chess);
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                 if(Chess[i][j]=='Q'&&a[i][j]=='*')bo=1;
            }
        }
        if(!bo)cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if(!Vis_Row[i]&&Valid(i,j))
        {
            Chess[i][j] = 'Q';
            Vis_Row[i] = 1;
            N_q(N - 1,j+1);
            Vis_Row[i] = 0;
            Chess[i][j] = '.';
        }
    }
}
void Suii() {
    n=8;
    Chess.resize(n);
    Vis_Row=vector<ll>(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Chess[i]+='.';
        }
    }
    for(int i=0;i<n;i++)
    {
        string lp;
        cin>>lp;
        a.push_back(lp);
    }
    N_q(n,0);
    cout<<cnt;
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