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
    void MergeGroups(int x, int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        if(leader1==leader2)return;
        if(Groups[leader1]>Groups[leader2])
            swap(leader1,leader2);
        parent[leader1] = leader2;
        Groups[leader2] += Groups[leader1];
        Num_comp --;
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
int id=1;
void $olve()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(!n && !m)return;
        vector<node> a(m);
        for(int i=0;i<m;i++)
            cin>>a[i].x>>a[i].y>>a[i].w;

        sort(a.begin(),a.end());

        int S,D,T;
        cin>>S>>D>>T;

        ll ans=1e18;
        DSU dsu(n);
        for(int i=0;i<m;i++)
        {
            a[i].w--;
            dsu.MergeGroups(a[i].x,a[i].y);
            if(dsu.SameGroup(S,D))
            {
                ans=T/(a[i].w)+(T%(a[i].w)!=0);
                break;
            }
        }
        cout<<"Scenario #"<<id++<<enl;
        cout<<"Minimum Number of Trips = "<<ans<<enl;
        if(id!=1)cout<<enl;
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