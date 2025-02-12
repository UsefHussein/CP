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
        if(Groups[leader1]>Groups[leader2])
            swap(leader1,leader2);
        parent[leader1] = leader2;
        Groups[leader2] += Groups[leader1];
        Num_comp --;
    }
};
struct node
{
    ll x,y;
    long double w;
    bool operator<(const node& other)const
    {
        return w < other.w;
    }
};
long double dis(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}
int id=1;
void $olve()
{
    if(id!=1)
        cout<<enl;

    id++;
    int m;
    cin>>m;
    vector<pair<int,int>> v(m);
    vector<node>a;
    for(int i=0;i<m;i++)
    {
        cin>>v[i].first>>v[i].second;
        for(int j=i-1;j>=0;j--)
        {
            a.push_back({i+1,j+1,dis(v[i].first,v[i].second,
                v[j].first,v[j].second)});
        }
    }
    sort(a.begin(),a.end());
    DSU dsu(m);
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        dsu.MergeGroups(x,y);
    }
    bool bo=0;
    for(int i=0;i<a.size();i++)
    {
        if(!dsu.SameGroup(a[i].x,a[i].y))
        {
            bo=1;
            cout<<a[i].x<<" "<<a[i].y<<enl;
            dsu.MergeGroups(a[i].x,a[i].y);
        }
    }
    if(!bo)
        cout<<"No new highways need"<<enl;

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