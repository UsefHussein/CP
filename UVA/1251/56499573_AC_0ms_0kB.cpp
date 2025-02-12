#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(s) (int) (s).size()

int n;
vector<pair<string,string>>a;
string st,en;
void bfs()
{
    queue<pair<string,ll>>q;
    map<string,bool>mp;
    q.push({st,0});
    while(!q.empty())
    {
        pair<string,ll> p = q.front();
        q.pop();
        if(p.F==en)return void(cout<<p.S<<enl);
        if(mp.count(p.F)||sz(p.F)>sz(en))continue;
        mp[p.F]=1;
        for(int i=0;i<n;i++)
        {
            string s = p.F;
            string h="";
            int sz=sz(p.F);
            for(int j=0;j<sz;j++)
            {
                h+=s[j];
                if(sz(h)==sz(a[i].F))
                {
                    if(h==a[i].F)
                    {
                        string t="";
                        for(int k=0;k<j-sz(a[i].F)+1;k++)t+=s[k];
                        for(auto k:a[i].S)t+=k;
                        for(int k=j+1;k<sz(s);k++)t+=s[k];
                        j+=sz(t)-sz(s);
                        s=t;
                        h="";
                        sz=sz(s);
                    }
                    else h.erase(h.begin());
                }
                if(sz(s)>sz(en))break;
            }
            if(sz(s)<=sz(en))q.push({s,p.S+1});
        }
    }
    cout<<-1<<enl;
}
void $olve()
{
    while(cin>>n)
    {
        if(!n)return;
        a.resize(n);
        for(int i=0;i<n;i++)cin>>a[i].F>>a[i].S;
        cin>>st>>en;
        bfs();
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