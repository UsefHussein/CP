#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define F first
#define S second
#define all(x)  x.begin(), x.end()
const ll Mod=1e9+7,N=5e3+5;
void Suii()
{
    int n,m;cin>>m>>n;
    vector<ll>a(n),ans(m),pr(n);
    for(int i=0;i<n;i++)cin>>a[i];
    set<ll>st;
    for(int i=0;i<n;i++)
    {
        if(st.count(a[i]))
        {
            auto it=st.lower_bound(a[i]);
            st.erase(it);
            pr[i]=sz(st);
        }
        else
        {
            st.insert(a[i]);
            pr[i]=sz(st);
        }
    }
    for(int i=n-2;i>=0;i--)pr[i]+=pr[i+1];
    st.clear();
    for(int i=0;i<n;i++)
    {
        if(st.count(a[i]))
        {
            auto it=st.lower_bound(a[i]);
            st.erase(it);
            ans[a[i]-1]-=pr[i];
        }
        else
        {
            st.insert(a[i]);
            ans[a[i]-1]+=pr[i];
        }
    }
    for(auto i:ans)cout<<i<<" ";
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