#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

void $olve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    multiset<int>s;
    for(int i=n-1;i>=0;i--)
    {
        auto it=s.lower_bound(a[i]);
        if(it!=s.begin())
        {
            it--;
            s.erase(it);
        }
        s.insert(a[i]);
    }
    cout<<s.size();
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