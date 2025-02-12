#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define int long long

void $olve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    b=a;
    reverse(b.begin(),b.end());
    if(is_sorted(a.begin(),a.end()))
        return void(cout<<"0\n");
    if(is_sorted(b.begin(),b.end()))
        return void(cout<<*max_element(a.begin(),a.end())+1<<"\n");

    int num=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
            num=max((a[i]+a[i-1]+1)/2,num);
    }
    for(int i=num-100;i<=num+100;i++)
    {
        vector<int>v=a;
        for(int j=0;j<n;j++)v[j]=abs(v[j]-i);
        if(is_sorted(v.begin(),v.end()))
            return void(cout<<i<<enl);
    }
    cout<<-1<<enl;

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
    int T = 1;cin>>T;
    while(T--)$olve();
    return 0;
}