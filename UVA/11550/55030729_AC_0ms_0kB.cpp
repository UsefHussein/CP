#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(x) int(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
const int N=30,Mod=1e9+7;
vector<int>adj[N];
int vis[N];
void DFS(int node)
{
    vis[node]=1;
    for(auto x:adj[node])
    {
        if(!vis[x])
            DFS(x);
    }
}
void $olve()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    vector<vector<bool>>vis(n,vector<bool>(n));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
    ll k=0;
    for(int i=0;i<m;i++)
    {
        int cnt=0,l=-1,r=-1;
        for(int j=0;j<n;j++)
        {
            if(a[j][i]==1)
            {
                if(!cnt)l=j;
                else r=j;
                cnt++;
            }
        }
        if(cnt!=2)return void(cout<<"No"<<enl);
        if(~r&&~l&&vis[l][r])return void(cout<<"No"<<enl);
        vis[l][r]=1;
    }
    cout<<"Yes"<<enl;
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
signed main()
{
    F_F();
    int T = 1;
    cin>>T;
    while(T--)$olve();
    return 0;
}