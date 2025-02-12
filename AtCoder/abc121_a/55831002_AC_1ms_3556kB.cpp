#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long


void $olve()
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    int h,w;
    cin>>h>>w;
    cout<<(n-h)*(m-w);
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