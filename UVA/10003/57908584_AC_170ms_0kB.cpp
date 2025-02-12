#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=55;
ll dp[N][N];
vector<int>a;
ll Dp(int i,int j)
{
    if(j-i==1)return 0;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    ret=1e9;
    for(int k=i+1;k<j;k++)
    {
        int cost=a[j]-a[i];
        ret=min({ret,Dp(k,j)+Dp(i,k)+cost});
    }
    return ret;
}
void $olve()
{
    int n;
    while (cin>>n)
    {
        if(!n)
            return;
        memset(dp,-1,sizeof(dp));
        int m;
        cin>>m;
        a.resize(m+3);
        for(int i=1;i<=m;i++)
            cin>>a[i];

        a[m+1]=n;
        cout<<"The minimum cutting is ";
        cout<<Dp(0,m+1)<<".\n";
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
    F_F();
    int T = 1;//cin>>T;
    while(T--)$olve();
    return 0;
}