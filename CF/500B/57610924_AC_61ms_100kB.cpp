#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

struct DSU
{
    vector<vector<int>> parents;
    vector<int> parent,Groups;
    vector<ll> sum;
    int Num_comp;
    DSU(int sz)
    {
        parents.resize(sz+5);
        for(int i=1;i<=sz;i++)
            parents[i].push_back(i);

        Num_comp = sz-1;
        parent=vector<int>(sz+5);
        sum=vector<ll>(sz+5);
        Groups= vector<int>(sz+5,1);
        iota(parent.begin(), parent.end(), 0);
        iota(sum.begin(), sum.end(), 0);
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

        for(auto it:parents[leader1])
        {
            parents[leader2].push_back(it);
        }
        parents[leader1].clear();
        parent[leader1] = leader2;
        Groups[leader2] += Groups[leader1];
        sum[leader2] += sum[leader1];
        Num_comp --;
    }

};
struct node
{
    ll x,y,w;
    bool operator<(const node& other)const
    {
        return w < other.w;
    }
};

void $olve()
{
    int n;
    cin>>n;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++)
        cin>>a[i];

    DSU dsu(n+5);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='1')
                dsu.MergeGroups(i,j);
            
        }

    for(int i=1;i<=n;i++)
    {
        vector<int> p=dsu.parents[dsu.FindLeader(i)];
        vector<int>v;
        sort(p.begin(),p.end());
        for(auto it:p)v.push_back(a[it]);
        sort(v.begin(),v.end());

        for(int j=0;j<v.size();j++)
            a[p[j]]=v[j];

    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
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