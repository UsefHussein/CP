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

    for(int i=0;i<26;i++)adj[i].clear();
    memset(vis,0,sizeof(vis));
    string s;
    while(cin>>s)
    {
        if(s[0]=='*')break;
        adj[s[1]-'A'].push_back(s[3]-'A');
        adj[s[3]-'A'].push_back(s[1]-'A');
    }
    ll trees=0,acorn=0;
    cin>>s;
    for(int i=0;i<sz(s);i++)
    {
        if(!(i&1)&&!vis[s[i]-'A'])
        {
            if(!sz(adj[s[i]-'A']))acorn++;
            else trees++;
            DFS(s[i]-'A');
        }
    }
    cout<<"There are "<<trees<<
    " tree(s) and "<<acorn<<" acorn(s)."<<enl;;
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