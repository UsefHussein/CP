#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=66;
ll dp[N][N][2],n,m;
ll ans[N][N];
int vis[N][N][2],id=1;
ll Dp(int i,int cnt,bool bo)
{
    //bo if adj secured
    if(i==n)return cnt==m;
    ll &ret=dp[i][cnt][bo];
    if(vis[i][cnt][bo]==id)return ret;
    vis[i][cnt][bo]=id;
    ret=0;
    for(int j=1;j<=n;j++)
    {
        if(i+j<=n&&i&&!bo)ret+=Dp(i+j,cnt+j-1,1);
        if(i+j<=n&&!i)ret+=Dp(i+j,cnt+j,1);
        if(i+j<=n&&(bo||!i))ret+=Dp(i+j,cnt,0);
    }
    return ret;
}
void $olve()
{
    int u,v;
    while(cin>>u>>v)
    {
        if(u<0)break;
        cout<<ans[u][v]<<enl;
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
    for(int i=1;i<=65;i++)
    {
        for(int j=0;j<=65;j++)
        {
            if(j>i)continue;
            n=i,m=j;
            ans[i][j]=Dp(0,0,0);
            id++;
        }
    }

    int T = 1;//cin>>T;
    while(T--)$olve();
    return 0;
}
