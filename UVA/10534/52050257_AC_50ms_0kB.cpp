#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e4+2;
ll dp[N][1005];
int n;

vector<pair<ll,ll>>pp1,pp2;
//ll Dp(ll i,ll prev)
//{
//    if(i==n)return 0;
//    ll &ret=dp[i][prev];
//    if(~ret)return ret;
//    ret=Dp(i+1,prev);
//    if(a[i]<prev)ret=max(ret,Dp(i+1,a[i])+1);
//    return ret;
//}
void sz_lis(vector<ll>&v,int pp)
{
    vector<ll>ans;
    ans.push_back(v[0]);
    pp1.push_back({0,sz(ans)});
    for (int i = 0; i < n; i++)
    {
        if (v[i] > ans.back())
        {
            ans.push_back(v[i]);
            if(pp)pp1.push_back({i,sz(ans)});
            else pp2.push_back({n-i-1,sz(ans)});
        } else
        {
            int ind = lower_bound(all(ans), v[i]) - ans.begin();
            ans[ind] = v[i];
        }
    }
}
void Suii()
{
    while(cin>>n)
    {
        vector<ll>a(n);
        for (int i = 0; i < n; i++)cin >> a[i];
        sz_lis(a,1);
        reverse(all(a));
        sz_lis(a,0);
        ll mx=1;
        for(auto [i,j]:pp1)
        {
            for (auto [ii, jj]: pp2)
            {
                if(ii==i)mx=max(mx,2*min(jj,j)-1);
            }
        }
        cout<<mx<<enl;
        pp1.clear();
        pp2.clear();
    }
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
int32_t main()
{
    F_F();
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}