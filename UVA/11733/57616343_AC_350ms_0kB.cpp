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
        return w < other.w;
    }
};
int id=1;
void $olve()
{
    ll n,m,c;
    cin>>n>>m>>c;
    vector<node> a(m);
    for(int i=0;i<m;i++)
        cin>>a[i].x>>a[i].y>>a[i].w;

    sort(a.begin(),a.end());
    DSU dsu(n);
    ll sum=0;
    vector<pair<ll,ll>> ans;
    for(int i=0;i<m;i++)
    {
        ans.push_back({(c*dsu.Num_comp)+sum,dsu.Num_comp});
        if(!dsu.SameGroup(a[i].x,a[i].y))
            dsu.MergeGroups(a[i].x,a[i].y),sum+=a[i].w;
    }
    ans.push_back({(c*dsu.Num_comp)+sum,dsu.Num_comp});
    cout<<"Case #"<<id++<<": ";
    ll ans2=1e18,cnt=0;
    for(auto [i,j]:ans)
    {
        if(ans2>=i)
        {
            if(ans2==i)cnt=max(cnt,j);
            else cnt=j;
            ans2=i;
        }
    }
    cout<<ans2<<" "<<cnt<<endl;
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