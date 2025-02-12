#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

ll GetBit(int n,int i)
{
    return (n>>i)&1;
}
ll SetBit1(int n,int i)
{
    return (n|(1<<i));
}
void $olve() {
    int n;cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<"0 ";
    for(int i=1;i<n;i++)
    {
        ll p=a[i]|a[i-1],op=0;
        for(int j=0;j<32;j++)
        {
            if(GetBit(a[i],j)!= GetBit(p,j))
            {
                op = SetBit1(op, j);
            }
        }
        a[i]=p;
        cout<<op<<" ";
    }
    cout<<enl;
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
    cin>>T;
    while(T--)$olve();
    return 0;
}