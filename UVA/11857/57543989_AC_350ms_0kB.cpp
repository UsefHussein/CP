#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

struct DSU
{
    vector<int> parent,Groups,Min;
    int Num_comp;
    DSU(int sz)
    {
        Num_comp = sz-1;
        parent=vector<int>(sz+5);
        Min=vector<int>(sz+5,1e9);
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
    void MergeGroups(int x, int y,int cost)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        if(leader1 == leader2)  return;
        if(Groups[leader1] > Groups[leader2])swap(leader1,leader2);
        parent[leader1] = leader2;
        Groups[leader2] += Groups[leader1];
        Min[leader2]=min({Min[leader2],Min[leader1],cost});
        Num_comp--;
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
int id=1;
void $olve() {
    ll n,m;
    while(cin>>n>>m)
    {
        if(!n&&!m)return;
        vector<node>a(m);
        DSU dsu(n);
        for(int i=0;i<m;i++)
            cin>>a[i].x>>a[i].y>>a[i].w;

        sort(a.begin(),a.end());
        ll ans=-1;
        for(int i=0;i<m;i++)
        {
            if(!dsu.SameGroup(a[i].x,a[i].y))
                dsu.MergeGroups(a[i].x,a[i].y,a[i].w);
            if(!dsu.Num_comp)
            {
                ans=a[i].w;
                break;
            }
        }
        if(!~ans)cout<<"IMPOSSIBLE"<<enl;
        else cout<<ans<<enl;
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