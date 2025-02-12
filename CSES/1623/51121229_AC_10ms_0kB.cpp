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
ll n,mn=1e18,sumA;
vector<ll>v;
void All_sub(vector<ll>&a,int i)
{
    if(i==n)
    {
        ll sum= accumulate(all(v),0ll);
        mn=min(mn,abs((2*sum)-sumA));
        return;
    }
    v.push_back(a[i]);
    All_sub(a,i+1);
    v.pop_back();
    All_sub(a,i+1);
}
void Suii()
{
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i],sumA+=a[i];
    All_sub(a,0);
    cout<<mn;
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
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}