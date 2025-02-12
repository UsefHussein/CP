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
const int N=2e2+2,Mod=1e9+7;
const ll NN = -1000000000000 ;
vector<ll>a;
ll n,m;
bool Valid(int mid)
{
    ll p=m;
    for(int i=0;i<n;i++)
    {
        ll k=a[i]/mid;
        p-=k;
        if(p<=0)return 1;
    }
    return 0;
}
void Suii()
{
    cin>>n>>m;
    a=vector<ll>(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(rall(a));
    ll l=1,r=1e9,mid,ans=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(Valid(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<enl;
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
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}