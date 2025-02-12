#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(s) (int)s.size()
struct node
{
    int x,y,h,r;
    bool operator<(const node& other) const
    {
        return  h > other.h;
        // Reverse logic for min-heap
    }
};
vector<node> a;
ll dis(int x1,int y1,int x2,int y2)
{
    double dx = abs(x1-x2), dy = abs(y1-y2);
    return sqrt(dx*dx+dy*dy);
}
void $olve()
{
    int n;
    cin>>n;
    a.resize(n);
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].h;
        mp[i]=a[i].h;
    }

    sort(a.begin(),a.end());
    a[0].r=a[0].h;
    for(int i=1;i<n;i++)
    {
        ll op=a[i].h;
        for(int j=i-1;j>=0;j--)
        {
            op=min(dis(a[i].x,a[i].y,a[j].x,a[j].y),op);
        }
        a[i].r=op;
    }
    for(int i=0;i<n;i++)
    {
        int x=mp[i];
        for(auto j:a)
        {
            if(x==j.h)cout<<j.r<<enl;
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
