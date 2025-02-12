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
    int n;
    cin>>n;
    vector<ll>a(n);
    ll suml=0,sumr=0;
    map<ll,ll>mp_l,mp_r;
    for(int i=0;i<n;i++) cin >> a[i],sumr+=a[i],mp_r[a[i]]++;
    for(int i=0;i<n;i++)
    {
        suml+=a[i];
        sumr-=a[i];
        mp_l[a[i]]++;
        mp_r[a[i]]--;
        if(abs(suml-sumr)&1)continue;
        ll k=abs(suml-sumr)/2;
        if(suml>sumr&&mp_l[k]>0||suml<sumr&&mp_r[k]>0)
        {
            cout<<"YES"<<enl;
            return;
        }
    }
    cout<<"NO";
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