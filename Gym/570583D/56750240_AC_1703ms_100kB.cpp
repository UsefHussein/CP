#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
int primeFactors(int num)
{
    int n=num,cnt=0;
    for(int i=2;i*i<=n;i++)
    {
        while(!(num%i))num/=i,cnt++;;
    }
    if(num>1)cnt++;
    return cnt;
}

void $olve()
{
    int x,y,k;
    cin>>x>>y>>k;
    if(k==1)
    {
        if(x!=y&&(x%y==0||y%x==0))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    int ans=primeFactors(x)+primeFactors(y);
    cout<<(ans>=k?"YES":"NO")<<enl;;
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