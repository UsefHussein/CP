#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define int long long

ll mx=0;
vector<ll> a;
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
        sum[leader2] += sum[leader1];
        mx=max(mx,sum[leader2]);
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
    a.resize(n+5);
    vector<ll> q(n+2),vis(n+2);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>q[i];
    vector<int> ans;
    DSU dsu(n+5);
    reverse(q.begin(),q.end());
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,a[q[i-1]]);
        ans.push_back(mx);
        dsu.sum[q[i]] = a[q[i]];
        vis[q[i]] = 1;
        if(i>1&&vis[q[i]-1])
            dsu.MergeGroups(q[i],q[i]-1);
        if(i<n&&vis[q[i]+1])
            dsu.MergeGroups(q[i],q[i]+1);

    }
    reverse(ans.begin(),ans.end());

    for(auto x:ans)cout<<x<<enl;
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