#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=2e5+5;
bool vis[N];
int cnt=0,n;
set<int> st;
map<pair<int,int>,bool>mp;
void dfs(int v)
{
    vis[v]=true;
    cnt++;
    vector<int>it;
    for(auto i:st)
    {
        if(!mp.count({i,v})&&!vis[i])
            it.push_back(i);
    }
    for(auto i:it)
        st.erase(i);
    for(auto i:it)
        dfs(i);
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
        st.insert(i+1);
    vector<int>ans;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
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