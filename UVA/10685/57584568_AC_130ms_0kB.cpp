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
        //if(Groups[leader1] > Groups[leader2])
        //    swap(leader1,leader2);
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
    int n,m;
    while(cin>>n>>m)
    {
        if(!n&&!m)return;
        map<string,int> mp;
        int id=0;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            mp[s]=id++;
        }
        DSU dsu(id);
        for(int i=0;i<m;i++)
        {
            string s,t;
            cin>>s>>t;
            if(!dsu.SameGroup(mp[s],mp[t]))
                dsu.MergeGroups(mp[s],mp[t]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,dsu.Groups[i]);
        cout<<ans<<enl;
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