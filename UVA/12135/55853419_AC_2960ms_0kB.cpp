#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

int n,m;

vector<vector<int>> g;

struct node {
    string s;
    int cnt,ind;
};

int t=1;
map<string,ll> mp;
void bfs ()
{
    queue<node> q;
    string S="";
    for(int i=0;i<n;i++)S+='0';
    q.push({S,0,0});
    while(!q.empty())
    {
        node p = q.front();
        q.pop();
        if(mp.count(p.s))continue;
        mp[p.s]=p.cnt;
        for(int i=1;i<=m;i++)
        {
            string s = p.s;
            for(int j=0;j<g[i].size();j++)
            {
                if(s[g[i][j]]=='0')s[g[i][j]]='1';
                else s[g[i][j]]='0';
            }

            q.push({s,p.cnt+1,i});
        }
    }
}
void $olve()
{
    cin>>n>>m;
    g=vector<vector<int>>(m+2);
    for(int i=0;i<m;i++)
    {
        int t;
        cin>>t;
        vector<int> v;
        while(t--)
        {
            int in;
            cin>>in;
            v.push_back(in);
        }
        g[i+1]=v;
    }
    cout<<"Case "<<t++<<":"<<enl;
    int q;
    cin>>q;
    bfs();
    while(q--)
    {
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        if(!mp.count(s))cout<<-1<<enl;
        else cout<<mp[s]<<enl;
    }
    cout<<enl;
    mp.clear();
}

void F_F()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

signed main()
{
    F_F();
    int T = 1;
    cin>>T;
    while(T--)$olve();
    return 0;
}