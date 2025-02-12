#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
const int N=5e3+2,Mod=1e9+7;
const ll NN = -1000000000000 ;
void Suii()
{
    int t;
    cin>>t;
    map<ll,ll>mp;
    ll ans=0;
    while(t--)
    {
        string s;
        cin>>s;
        ll cnt=0,n=sz(s);
        vector<ll>pr(n),su(n);
        for(int i=0;i<n;i++)
        {
            if(s[i]==')')cnt--;
            else cnt++;
            pr[i]=cnt;
        }cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==')')cnt--;
            else cnt++;
            su[i]=cnt;
        }cnt=0;
        bool bo=0;
        for(int i=n-2;i>=0;i--)if(pr[i]<0&&su[i+1]>0)bo=1;
        for(int i=n-2;i>=0;i--)if(pr[i+1]<0&&su[i]>0)bo=1;
        if(bo)continue;
        for(auto i:s)
        {
            if(i==')')cnt--;
            else cnt++;
        }
        if(mp[-cnt]>0)
        {
            ans++;
            mp[-cnt]--;
        }
        else mp[cnt]++;
    }
    cout<<ans;
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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}