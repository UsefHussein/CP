#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double  dd;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
vector<ll>ans,a;
void rec(int fr,int la,int mx)
{
    if(fr>la)return;
    int ind=0;
    for(int i=fr;i<=la;i++)
    {
        if(a[i]>a[ind])ind=i;
    }
    ans[ind]=mx;
    rec(ind+1,la,mx+1);
    rec(fr,ind-1,mx+1);
}
void Suii()
{
    int n;
    cin >> n;
    a.resize(n+1);
    ans.resize(n+1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    rec(1,n,0);
    for(int i = 1; i <= n; i++)cout<<ans[i]<<" ";
    cout<<enl;
    ans.clear();
    a.clear();
}
void Fast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void File()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int32_t main()
{
    Fast();
    File();
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}