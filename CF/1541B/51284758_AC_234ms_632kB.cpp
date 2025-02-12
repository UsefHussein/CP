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
void Suii()
{

    int n,k;cin>>n;
    map<ll,ll>mp;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        if(i!=1)
        {
            ll j=((i+1)/k)+((i+1)%k!=0);
            while(1)
            {
                ll op=(k*j)-i;
               // cout<<op<<" "<<mp[op]<<" "<<j<<" "<<i<<" "<<ans<<enl;
                if(op>(i))break;
                if(mp[op]==j)ans++;
                j++;
            }
           // cout<<"\n";
        }
        mp[i]=k;
    }
    cout<<ans<<enl;
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