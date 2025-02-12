#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=2e5+5;
bitset<N> bits;
int cnt=0,n;
set<int> st;
map<pair<int,int>,bool>mp;
void dfs(int v)
{
    bits[v]=0;
    cnt++;
    for(int i=bits._Find_first();i< bits.size();i = bits._Find_next(i))
    {
        if(!mp.count({i,v}))
            dfs(i);
    }
}
void $olve()
{
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        mp[{x,y}]=1;
        mp[{y,x}]=1;
    }
    for(int i=0;i<n;i++)
        bits[i+1]=1;
    vector<int>ans;
    for(int i=1;i<=n;i++)
    {
        if(bits[i])
        {
            dfs(i);
            ans.push_back(cnt);
            cnt=0;
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<enl;
    for(auto i:ans)
        cout<<i<<" ";
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
    int T = 1;// cin>>T;
    while(T--)$olve();
    return 0;
}