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
        return w < other.w;
    }
};

void $olve()
{
    int n;
    cin>>n;
    DSU dsu(n+1);
    vector<string> v(n+1);
    v[0]="0000";
    for(int i=1;i<=n;i++)
        cin>>v[i];

    auto Min_cost=[&](string a,string b)->ll
    {
        ll sum=0;
        for(int i=0;i<4;i++)
        {
            ll f=a[i]-'0';
            ll s=b[i]-'0';
            ll c1=0,c2=0;
            for(int j=f;;)
            {
                if(j==s)break;
                j++;c1++;
                if(j==10)j=0;
            }
            for(int j=f;;)
            {
                if(j==s)break;
                j--;c2++;
                if(j<0)j=9;
            }
            sum+=min({c1,c2});
        }
        return sum;
    };
    vector<node>a;
    ll p=1e18;
    for(int i=1;i<=n;i++)
    {
        p=min(p,Min_cost(v[i],"0000"));
        for(int j=i+1;j<=n;j++)
            a.push_back({i,j,Min_cost(v[i],v[j])});
    }
    sort(a.begin(),a.end());

    ll sum=0;
    for(int i=0;i<a.size();i++)
    {
        if(!dsu.SameGroup(a[i].x,a[i].y))
            dsu.MergeGroups(a[i].x,a[i].y),sum+=a[i].w;
    }
    cout<<sum+p<<endl;
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