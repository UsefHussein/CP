#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second

void $olve()
{
    int se,n,time;
    cin>>se>>n>>time;
    vector<int> last_acc(n+2),bo(n+2),bef(n+2);
    vector<multiset<pair<int,int>>>st(n+2);
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        bef[i]=x;
    }
    int q,cnt=0;cin>>q;
    while(q--)
    {
        int sec,sid,pos;cin>>sec;
        string s;cin>>s;
        cin>>sid>>pos;
        if(sec/time+1>cnt)cnt=sec/time+1;
        if(bo[pos]!=cnt)
        {
            last_acc[pos]=bef[pos];
            st[pos].clear(),bo[pos]=cnt;
        }
        if(s=="Get")
        {
            auto it=st[pos].lower_bound({sid,-1e9+1});
           if(it==st[pos].end()||it->F!=sid)cout<<last_acc[pos]<<enl;
            else cout<<it->S<<enl;
        }
        else
        {
            int val;
            cin>>val;
            auto it=st[pos].lower_bound({sid,-1e9+1});
            if(it!=st[pos].end()&&it->F==sid)st[pos].erase(it);
            st[pos].insert({sid,val});
            bef[pos]=val;
        }
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
