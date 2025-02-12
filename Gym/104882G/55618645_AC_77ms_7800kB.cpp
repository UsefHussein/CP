#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int) (s).size()

const int N=1e5+1;

int n;

ll dp[N][4];

vector<int>a;

ll Dp(int i,int cnt)
{
    if(i==n)return 0;
    ll &ret = dp[i][cnt];
    if(~ret)return ret;
    ret=-1e18;
    if(cnt==2)
    {
        ret=max(ret,Dp(i+1,0)+max(5,a[i]));
    }
    else {
        ret=max(ret,Dp(i+1,0)+5);
        ret=max(ret,Dp(i+1,cnt+1)+6);
    }
    return ret;
}
void $olve()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<Dp(0,0)<<endl;
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