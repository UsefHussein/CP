#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=1e5+1;
vector<int>adj[N],ans;
bool vis[N],mark[N];
void $olve()
{
    int n,root;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(!~x)root=i;
        else
        {
            mark[i]=y==1;
            adj[x].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        ll cnt=mark[i];
        for(auto j:adj[i])cnt+=mark[j];
        if(cnt==adj[i].size()+1)ans.push_back(i);
    }
    if(!ans.size())cout<<-1<<enl;
    else {
        for(auto i:ans)cout<<i<<" ";
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
    int T = 1;
    //cin>>T;
    while(T--)$olve();
    return 0;
}