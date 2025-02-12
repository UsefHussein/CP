#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

int n,m;

string s,e;

vector<int> g;

struct node {
    string s;
    int cnt;
};

int t=0,ans=-1;
map<string,ll> mp;
void bfs ()
{
    queue<node> q;
    q.push({s,0});
    while(!q.empty())
    {
        node p = q.front();
        q.pop();
        if(p.s==e)
        {
            ans=p.cnt;
            return;
        }
        if(mp.count(p.s))continue;
        mp[p.s]=1;
        for(int i=1;i<=n;i++)
        {
            string o=p.s;
            ll op=stoi(o)+g[i];
            if(op>=10000)op-=10000;
            o=to_string(op);
            while (o.size()<4)o='0'+o;
            q.push({o,p.cnt+1});
        }
    }
}
void $olve()
{

    while (cin>>s>>e>>n)
    {
        if(!n)return;
        g=vector<int>(n+2);
        for(int i=0;i<n;i++)cin>>g[i+1];
        bfs();
        cout<<"Case "<<++t<<": ";
        if(~ans)cout<<ans;
        else cout<<"Permanently Locked";
        cout<<enl;
        mp.clear();
        ans=-1;
    }
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
    //cin>>T;
    while(T--)$olve();
    return 0;
}