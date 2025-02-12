#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

struct DSU
{
    vector<int> parent,Groups;
    vector<ll> Sum;
    vector<set<int>> Child;
    int Num_comp;
    DSU(int sz)
    {
        Num_comp = sz;
        parent=vector<int>(sz+5);
        Groups= vector<int>(sz+5,1);
        Sum= vector<ll>(sz+5);
        Child= vector<set<int>>(sz+5);
        for(int i=1;i<=sz;i++)
            Child[i].insert(i);
        iota(parent.begin(), parent.end(), 0);
        iota(Sum.begin(), Sum.end(), 0);
    }
    int FindLeader(int v)
    {
        return parent[v];
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
        if(Groups[leader1] > Groups[leader2])
            swap(leader1,leader2);

        for(auto x:Child[leader1])
            Child[leader2].insert(x),parent[x] = leader2;

        Child[leader1].clear();
        Groups[leader2] += Groups[leader1];
        Sum[leader2] += Sum[leader1];
        Num_comp--;
    }
    void Moving(int u,int v)
    {
        int x=FindLeader(u);
        int y=FindLeader(v);
        if(x==y)return;
        Child[x].erase(Child[x].find(u));
        Child[y].insert(u);
        Sum[x]-=u;
        Sum[y]+=u;
        Groups[x] --;
        Groups[y] ++;
        parent[u] = y;
    }
};

void $olve()
{
    int n,m;
    while(cin>>n>>m)
    {
        DSU dsu(n+5);
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
                dsu.Moving(u,v);
            }
            else
            {
                int x;
                cin>>x;
                int p=dsu.FindLeader(x);
                cout<<dsu.Groups[p]<<" "<<dsu.Sum[p]<<enl;
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