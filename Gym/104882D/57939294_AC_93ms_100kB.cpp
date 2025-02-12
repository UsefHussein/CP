#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

void $olve()
{
    int n;
    cin>>n;
    ll ans1=0,ans2=0;
    bool bo=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            if(i%7==0&&!bo)
            {
                ans1++;
            }
            else if((i%3==0))ans2++,bo=0;
        }
    }
    cout<<ans2<<" "<<ans1<<enl;
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