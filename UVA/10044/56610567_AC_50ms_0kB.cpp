#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

vector<vector<int>>adj;
vector<int>dis;
int root;
void bfs()
{
    queue<int> q;
    q.push(root);
    dis[root]=0;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(auto child:adj[p])
        {
            if(dis[child]==-1)
            {
                dis[child]=dis[p]+1;
                q.push(child);
            }
        }
    }
}
int d=1;
void $olve()
{
    int n,q;
    cin>>n>>q;
    cin.ignore();
    map<string,int>mp;
    int id=0;
    vector<vector<int>>a;
    for(int i=0;i<n;i++)
    {
        string s,t="",temp="";
        getline(cin,s);
        vector<int>v;
        for(int j=0;j<s.length();j++)
        {
            if(s[j]==','||s[j]==':')
            {
                if(temp.size())
                {
                    temp+=t;
                    if(temp[0]==' ')temp.erase(temp.begin());
                    if(!mp.count(temp))
                    {
                        if(temp=="Erdos, P.")root=id;
                        mp[temp]=id++;
                    }
                    v.push_back(mp[temp]);
                    temp="";
                    t="";
                }
                else
                {
                    temp+=t+s[j];
                    t="";
                }
                if(s[j]==':')break;
            }
            else t+=s[j];
        }
        a.push_back(v);
    }
    adj=vector<vector<int>>(id+10);
    dis=vector<int>(id+10,-1);
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            for(int k=j+1;k<a[i].size();k++)
            {
                if(a[i][j]==a[i][k])continue;
                adj[a[i][j]].push_back(a[i][k]);
                adj[a[i][k]].push_back(a[i][j]);
            }
        }
    }
    bfs();
    cout<<"Scenario "<<d++<<enl;
    while (q--)
    {
        string s;
        getline(cin,s);
        cout<<s<< " ";
        if(!mp.count(s))
        {
            cout<<"infinity"<<enl;
            continue;
        }
        ll ans=dis[mp[s]];
        if(!~ans)cout<<"infinity";
        else cout<<ans;
        cout<<"\n";
    }
    root=0;
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
    cin>>T;
    cin.ignore();
    while(T--)$olve();
    return 0;
}