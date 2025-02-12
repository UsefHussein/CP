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
        if(leader1 == leader2)  return;
        if(Groups[leader1] > Groups[leader2])swap(leader1,leader2);
        parent[leader1] = leader2;
        Groups[leader2] += Groups[leader1];
        Num_comp--;
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
long double Dis(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}
void $olve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    while(1)
    {
        int x,y;
        cin>>x;
        if(x==-1)break;
        cin>>y;
        v.push_back({x,y});
    }
    auto Valid=[&](int mid)->bool
    {
        DSU dsu(v.size());
        for(int i=0;i<v.size();i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                long double p=Dis(v[i].first,v[i].second
                    ,v[j].first,v[j].second);

                p=ceil(p);
                if(mid>=(ll)p)
                    dsu.MergeGroups(i,j);
            }
        }
        return dsu.Num_comp<=n;
    };
    int l=0,r=1e9,ans;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(Valid(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
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