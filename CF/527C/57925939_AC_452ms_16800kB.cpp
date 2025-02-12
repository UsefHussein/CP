#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

void $olve()
{
    int n,m,q;
    cin>>n>>m>>q;
    multiset<ll>stv={0,n},sth={0,m},stvv={n},sthh={m};
    while(q--)
    {
        char ch;
        cin>>ch;
        int x;
        cin>>x;
        if(ch=='H')
        {
            auto it=sth.lower_bound(x);
            auto itt=it;
            itt--;
            sthh.erase(sthh.find((*it)-(*itt)));
            sthh.insert((*it)-x);
            sthh.insert(x-(*itt));
            sth.insert(x);
        }
        else
        {
            auto it=stv.lower_bound(x);
            auto itt=it;
            itt--;
            stvv.erase(stvv.find((*it)-(*itt)));
            stvv.insert((*it)-x);
            stvv.insert(x-(*itt));
            stv.insert(x);
        }
        cout<<*sthh.rbegin() * *stvv.rbegin()<<enl;
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