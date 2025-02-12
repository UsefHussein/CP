#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

struct DSU
{
    vector<int> parent,Groups;
    int Num_comp;
    DSU(int sz)
    {
        Num_comp = sz-1;
        parent=vector<int>(sz+5);
        Groups= vector<int>(sz+5,1);
        iota(parent.begin(),parent.end(),0);
    }
    int FindLeader(int v)
    {
        if(parent[v]==v)return v;
        return parent[v]=FindLeader(parent[v]);
    }
    bool SameGroup(int u,int v)
    {
        return FindLeader(u) == FindLeader(v);
    }
    void MergeGroups(int x, int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        if(leader1==leader2)return;
        // if(Groups[leader1]>Groups[leader2])
        //     swap(leader1,leader2);
        parent[leader1] = leader2;
        Groups[leader2] += Groups[leader1];
        Num_comp --;
    }
};
const int N=1e7+5;
void $olve()
{
    ll ans=0;
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    vector<bool> vis(N);
    for(int i=0;i<n;i++)
        cin>>a[i].first>>a[i].second;
    reverse(a.begin(),a.end());
    DSU dsu(N);
    for(int i=0;i<n;i++)
    {
        int u=a[i].first,v=a[i].second;
        bool ok=false;
        for(int j=u;j<=v;)
        {
            int u=j;
            j=dsu.parent[dsu.FindLeader(j)]+1;
            if(!vis[u])
            {
                ok=true;
                dsu.MergeGroups(u,v);
                vis[u]=1;
            }
        }
        if(ok)ans++;
    }
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
    int T = 1;cin>>T;
    while(T--)$olve();
    return 0;
}