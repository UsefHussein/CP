#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(x) x.size()

const int N=5e3+10;
int n,id=0;
int vis[N][N];
vector<vector<int>> adj;
int dp[N][N];
int Dp(int node,int par)
{
    int &ret=dp[node][par];
    if(vis[node][par]==id) return ret;
    vis[node][par]=id;
    ret=0;
    for(auto i:adj[node])
    {
        if(i!=par)
        {
            ret=max(ret,Dp(i,node)+1);
        }
    }
    return ret;
}
void $olve()
{

    while(cin>>n)
    {
        id++;
        adj=vector<vector<int>>(n+2);
        for(int i=1;i<=n;i++)
        {
            int y;
            cin>>y;
            while(y--)
            {
                int x;
                cin>>x;
                adj[i].push_back(x);
            }
        }
        vector<int>d7k(n+1);
        int mn=1e9,mx=0;
        for(int i=1;i<=n;i++)
        {
            int ans=Dp(i,0);
            d7k[i]=ans;
            mn=min(mn,ans);
            mx=max(mx,ans);
        }
        vector<int>ansp,answ;
        for(int i=1;i<=n;i++)
        {
            if(d7k[i]==mn)ansp.push_back(i);
            if(d7k[i]==mx)answ.push_back(i);
        }
        cout<<"Best Roots  : "<<ansp[0];
        for(int i=1;i<sz(ansp);i++)cout<<" "<<ansp[i];
        cout<<enl<<"Worst Roots : "<<answ[0];
        for(int i=1;i<sz(answ);i++)cout<<" "<<answ[i];
        cout<<enl;
    }

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
    while(T--)$olve();
    return 0;
}