#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define F first
#define S second
#define sz(s) (int)s.size()
void $olve()
{
    int n=4;
    set<int> s;
    while(n--)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    for(int i=1;i<=5;i++)
    {
        if(!s.count(i))
        {
            cout<<i<<enl;
            return;
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
    //F_F();
    int T = 1;//cin>>T;
    while(T--)$olve();
    return 0;
}
