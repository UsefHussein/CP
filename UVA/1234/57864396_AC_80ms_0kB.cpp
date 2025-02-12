#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

struct DSU
{
    vector<int> parent,Groups;
    vector<multiset<int>> st;
    int Num_comp;
    DSU(int sz)
    {
        Num_comp = sz-1;
        parent=vector<int>(sz+5);
        st=vector<multiset<int>>(sz+5);
        Groups= vector<int>(sz+5,1);
        iota(parent.begin(), parent.end(), 0);
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
    void MergeGroups(int x, int y,int w)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        if(leader1 == leader2)  return;
        if(Groups[leader1] > Groups[leader2])
            swap(leader1,leader2);

        st[leader2].insert(w);
        for(auto i:st[leader1])
            st[leader2].insert(i);

        st[leader1].clear();
        parent[leader1] = leader2;
        Groups[leader2] += Groups[leader1];
        Num_comp--;
    }
    ll Mincost(int v)
    {
        int x=FindLeader(v);
        int o=*st[x].begin();
        st[x].erase(st[x].begin());
        return o;
    }
};
struct node
{
    ll x,y,w;
    bool operator<(const node& other)const
    {
        return w > other.w;
    }
};
void $olve()
{
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    vector<node> v(m);
    for(int i=0;i<m;i++)
        cin>>v[i].x>>v[i].y>>v[i].w;

    sort(v.begin(),v.end());
    ll ans=0;
    for(int i=0;i<m;i++)
    {
        if(!dsu.SameGroup(v[i].x,v[i].y))
            dsu.MergeGroups(v[i].x,v[i].y,v[i].w);

        else
            ans+=v[i].w;
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