#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
const int N=1e2+1,Mod=1e9+7;
vector<int>Adj[N];
void Solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)cout<<sz(Adj[i])<<enl;
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
    //cin>>T;
    while(T--) Solve();
    return 0;
}