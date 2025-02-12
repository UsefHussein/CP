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
    ll p,q,r,n;
    cin>>n>>p>>q>>r;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<ll>ml(n),mr(n),mxl(n),mxr(n);
    ml=mr=mxl=mxr=a;
    for(int i=1;i<n;i++)
    {
        ml[i]=min(ml[i],ml[i-1]);
        mxl[i]=max(mxl[i],mxl[i-1]);
    }
    for(int i=n-2;i>=0;i--)
    {
        mr[i]=min(mr[i],mr[i+1]);
        mxr[i]=max(mxr[i],mxr[i+1]);
    }
    ll ans=LLONG_MIN;
    for(int i=0;i<n;i++)
    {
        ll k=0;
        k+=(p>0)?1ll*mxl[i]*p:1ll*ml[i]*p;
        k+=(r>0)?1ll*mxr[i]*r:1ll*mr[i]*r;
        k+=1ll*q*a[i];
        ans=max(ans,k);
    }
    cout<<ans;
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
int main() {
    Fast();
    File();
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}