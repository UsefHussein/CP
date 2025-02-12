#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(s) (int)s.size()
void $olve()
{
    int n,m;
    cin>>n>>m;
    ll sum=m*2;
    cout<<3<<enl<<m<<" "<<m<<" ";
    ll p=n*3-sum;
    cout<<p;
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
