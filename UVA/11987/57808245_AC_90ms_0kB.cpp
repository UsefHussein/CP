#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

struct DSU
{
    vector<int> parent,Groups;
    vector<ll>Sum;
    int Num_comp,Sz;
    DSU(int sz)
    {
        Sz=sz;
        Num_comp = sz-1;
        parent=vector<int>(sz*2+5);
        Groups= vector<int>(sz+5);
        Sum= vector<ll>(sz+5);
        for(int i=1;i<=sz;i++)
        {
            parent[i+sz]=parent[i]=i+sz;
            Sum[i]=i;
            Groups[i]=1;
        }
    }
    int FindLeader(int v)
    {
        return parent[v]==v?v:parent[v]=FindLeader(parent[v]);
    }
    bool SameGroup(int u,int v)
    {
        return FindLeader(u) == FindLeader(v);
    }
    void MergeGroups(int x, int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        if(leader1 == leader2)  return;
        parent[leader1] = leader2;
        Groups[leader2-Sz] += Groups[leader1-Sz];
        Sum[leader2-Sz] += Sum[leader1-Sz];
        Num_comp--;
    }
    void Move(int u,int v)
    {
        int x = FindLeader(u);
        int y = FindLeader(v);
        if(x==y)return;
        Groups[x-Sz] --;
        Groups[y-Sz] ++;
        Sum[x-Sz] -=u;
        Sum[y-Sz] +=u;
        parent[u]=y;
    }
};
void $olve()
{
    int n,m;
    while(cin>>n>>m)
    {
        DSU dsu(n);
        while(m--)
        {
            int t;
            cin>>t;
            if(t==1)
            {
                int u,v;
                cin>>u>>v;
                dsu.MergeGroups(u,v);
            }
            else if(t==2)
            {
                int u,v;
                cin>>u>>v;
                dsu.Move(u,v);
            }
            else
            {
                int x;
                cin>>x;
                cout<<dsu.Groups[dsu.FindLeader(x)-n]<<" ";
                cout<<dsu.Sum[dsu.FindLeader(x)-n]<<enl;
            }
        }
    }
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
    int T = 1;//cin>>T;
    while(T--)$olve();
    return 0;
}