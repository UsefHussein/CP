#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

ll dp[101][100001];
vector<int>st;
vector<int>a;
int n;
ll Dp(int i,int sum)
{
    if(i==n)
    {
        if(sum)st.push_back(sum);
        return 1;
    }
    ll &ret = dp[i][sum];
    if(~ret)return ret;
    ret=0;
    ret+=Dp(i+1,sum);
    ret+=Dp(i+1,sum+a[i]);
    return ret;
}
void $olve()
{
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    memset(dp,-1,sizeof(dp));
    ll ans=Dp(0,0);
    sort(st.begin(),st.end());
    st.erase(unique(st.begin(),st.end()),st.end());
    cout<<st.size()<<enl;
    for(auto x:st)
        cout<<x<<" ";
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