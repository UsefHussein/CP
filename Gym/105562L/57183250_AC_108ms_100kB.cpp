#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(s) (int)s.size()
int n,m,x,y;
vector<int> sh,bo;
bool valid(int mid)
{
    int k=0,p=n-mid;
    for(int i=0,j=0;i<m;i++)
    {
        if(j<n&&bo[i]<=sh[j])
        {
            k++;
            if(k==y&&!p)
            {
                k=0;
                mid--;
                j++;
                continue;
            }
        }
        else return 0;
        if(k==x)k=0,p--,j++;
    }
    return mid>=0;
}
bool val()
{
    int k=0;
    for(int i=0,j=0;i<m;i++)
    {
        if(j<n&&bo[i]<=sh[j])k++;
        else return 0;
        if(k==x)k=0,j++;
    }
    return 1;
}
void $olve()
{
    cin>>n>>m>>x>>y;
    sh.resize(n);
    bo.resize(m);
    for(int i=0;i<n;i++)cin>>sh[i];
    for(int i=0;i<m;i++)cin>>bo[i];
    sort(sh.rbegin(),sh.rend());
    sort(bo.rbegin(),bo.rend());
    if(!val())return void(cout<<"impossible"<<enl);
    int l=1,r=n,ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(valid(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<enl;
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
