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
        if(leader1 == leader2)  return;
        if(Groups[leader1] > Groups[leader2])
            swap(leader1,leader2);
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
vector<ll> v(101);
void pre()
{
    v[1]=v[2]=1;
    ll p=1,c=3;
    for(int i=3;i<101;i++)
    {
        ll sum=1;
        for(int j=1;j<=p;j++)
        {
            sum*=c;
            sum%=2000000011;
        }
        v[i]=sum;
        c++,p++;
    }
}
int id=1;
void $olve()
{
    int n;
    cin>>n;
    cout<<"Case #"<<id++<<": "<<v[n]<<enl;
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
    pre();
    int T = 1;cin>>T;
    while(T--)$olve();
    return 0;
}