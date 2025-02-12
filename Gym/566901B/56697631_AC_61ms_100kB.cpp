#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

void $olve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    vector<vector<int>> su(2,vector<int>(n+2));
    for(int i=0;i<n;i++)cin>>a[i];
    int cntev=0,cntod=0,op=0;
    for(int i=n-1;i>=0;i--)
    {
        if(!op)cntev++;
        else cntod++;
        su[0][i]=su[0][i+1];
        su[1][i]=su[1][i+1];
        if(a[i])
        {
            if(!op)su[op][i]=cntev;
            else su[op][i]=cntod;
            op^=1;
        }
    }
    ll ans=0;op^=1;
    for(int i=0;i<n;i++)
    {
        ans+=su[op][i];
        if(a[i])op^=1;
    }
    cout<<ans<<" ";
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