#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

struct DSU
{
    vector<int> parent,Groups;
    vector<ll> sum;
    int Num_comp;
    DSU(int sz)
    {
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
int T = 1;
void $olve()
{
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    map<string,int> mp;
    int id=0;
    vector<node> a;
    for(int i=0;i<m;i++)
    {
        string s,t;
        cin>>s>>t;
        if(!mp.count(s))mp[s]=id++;
        if(!mp.count(t))mp[t]=id++;
        int w;
        cin>>w;
        a.push_back({mp[s],mp[t],w});
    }
    sort(a.begin(),a.end());
    ll ans=0;
    for(int i=0;i<a.size();i++)
    {
        if(!dsu.SameGroup(a[i].x,a[i].y))
            dsu.MergeGroups(a[i].x,a[i].y),ans+=a[i].w;
    }
    cout<<ans<<enl;
    if(T)cout<<enl;
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
    cin>>T;
    while(T--)$olve();
    return 0;
}