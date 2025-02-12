#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
ll ans;
struct DSU
{
    vector<int> parent,Groups;
    int Num_comp;
    DSU(int sz)
    {
        Num_comp = sz;
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
        if(leader1 == leader2)  return;
        if(Groups[leader1] > Groups[leader2])
            swap(leader1,leader2);
        parent[leader1] = leader2;
        Groups[leader2] += Groups[leader1];
        Num_comp --;
        ans=Groups[leader2];
    }
};
struct node
{
    ll w,x,y;
    bool operator<(const node& other)const
    {
        return w < other.w;
    }
};

void $olve()
{
    int n;
    cin>>n;
    map<string,int>mp;
    vector<pair<int,int>> a;
    int id=1;
    for(int i=0;i<n;i++)
    {
        string t,m;
        cin>>t>>m;
        int u=0,v=0;
        if(!mp.count(t))mp[t]=id++;
        if(!mp.count(m))mp[m]=id++;
        u=mp[t];v=mp[m];
        a.push_back(make_pair(u,v));
    }
    DSU dsu(mp.size());
    for(int i=0;i<a.size();i++)
    {
        if(!dsu.SameGroup(a[i].first,a[i].second))
            dsu.MergeGroups(a[i].first,a[i].second);

        cout<<dsu.Groups[dsu.FindLeader(a[i].first)]<<enl;
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
    int T = 1;cin>>T;
    while(T--)$olve();
    return 0;
}