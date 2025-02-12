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
    int n;cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));
    if(n==1)
    {
        cout<<a[0]-1<<enl;
        return;
    }
    ll ans=a[0]-1;
    a[0]=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            ans+=a[i]-a[i-1]-1;
            a[i]=a[i-1]+1;
        }
    }
    //for(auto i:a)cout<<i<<" ";

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
int main() {
    Fast();
    File();
    int T_C =1;
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}