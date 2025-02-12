#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define enl '\n'
#define ll long long

const int N=1e5;

map<string,int>vis;

string s,m;

bool prime(int x)
{
    if(x < 2)
        return false;

    for(ll i = 2 ; i*i <=x ;i++ ){
        if(x%i == 0)
            return false;
    }
    return true;
}

bool valid(string u)
{
    return !vis.count(u)&&prime(stoi(u));
}

void bfs()
{
    queue<pair<string,int>> q;
    q.push({s,0});
    while(!q.empty())
    {
        pair<string,int> p = q.front();
        q.pop();
        vis[p.first]=1;
        if(p.first==m)
        {
            return void(cout<<p.second<<enl);
        }
        for(int i=0;i<4;i++)
        {
            for(int dg=0;dg<=9;dg++)
            {
                if(!i&&!dg)continue;
                char t= p.first[i];
                p.first[i]=dg+'0';
                if(valid( p.first))
                {
                    q.push({ p.first,p.second+1});
                }
                p.first[i]=t;
            }
        }
    }
    cout<<"Impossible"<<enl;
}
void $olve()
{
    cin>>s>>m;
    bfs();
    vis.clear();
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