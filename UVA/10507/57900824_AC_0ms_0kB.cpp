#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long


void $olve()
{
    int n,m;
    while(cin>>n>>m)
    {
        auto p=[&](char c)->int
        {
          return c-'A';
        };
        vector<int>adj[30];
        vector<bool>vis(30);
        string s;
        cin>>s;
        vis[p(s[0])]=vis[p(s[1])]=vis[p(s[2])]=1;
        while(m--)
        {
            char u,v;
            cin>>u>>v;
            adj[p(u)].push_back(p(v));
            adj[p(v)].push_back(p(u));
        }
        int ans=0;
        set<int>ch;
        bool flag=ch.size()==n-3;
        while(!flag)
        {
            bool bo=0;
            ans++;
            for(int i=0;i<26;i++)
            {
                if(vis[i]||adj[i].empty())continue;
                int cnt=0;
                for(auto j:adj[i])
                    if(vis[j])
                        cnt++;

                if(cnt>=3&&!ch.count(i))
                {
                    bo=1;
                    ch.insert(i);
                }
            }
            if(!bo||ch.size()==n-3)flag=true;
            for(auto i:ch) {
                vis[i]=1;
            }
        }
        if(ch.size()!=n-3)
            cout<<"THIS BRAIN NEVER WAKES UP\n";
        else
            cout<<"WAKE UP IN, "<<ans<<", YEARS\n";
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