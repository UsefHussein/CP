#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
const int N=1e3+5,Mod=1e9+7;
vector<int>adj[N];
void Solve()
{
    int p;cin>>p;
    int mn=1e9;
    for(int i=0;i<=p;i++)
    {
        int cnt=0;
        string str;
        getline(cin,str);
        stringstream s(str);
        int word;
        while (s >> word)cnt++;
        if(cnt)mn=min(mn,cnt);
        adj[cnt].push_back(i);
    }
    for(int i=0;i<sz(adj[mn])-1;i++)cout<<adj[mn][i]<<" ";
    cout<<adj[mn].back()<<enl;
    for(int i=0;i<=1000;i++)adj[i].clear();
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
    while(T--) Solve();
    return 0;
}