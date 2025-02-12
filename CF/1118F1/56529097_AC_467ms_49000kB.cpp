#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define int long long

const int N=3e5+5;
vector<int>adj[N];
bool vis[N];
int color[N],Blue[N],Red[N],b,r,ans;
void dfs(int node)
{
    vis[node]=true;
    Blue[node]=color[node]==2;
    Red[node]=color[node]==1;
    for(auto i:adj[node])
    {
        if(!vis[i])
        {
            dfs(i);
            Blue[node]+=Blue[i];
            Red[node]+=Red[i];
            if(Blue[i]==b&&!Red[i])ans++;
            if(!Blue[i]&&Red[i]==r)ans++;
        }
    }
}
void $olve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        color[i+1]=x;
        if(x==1)r++;
        else if(x==2)b++;
    }
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout<<ans<<enl;
}
void F_F()
{
    cin.tie(0)->sync_with_stdio(0);
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
    while(T--)$olve();
    return 0;
}