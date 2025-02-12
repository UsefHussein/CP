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
ll GetBit(ll n,int i)
{
    return (n>>i)&1ll;
}
ll SetBit1(ll n,int i)
{
    return (n|(1ll<<i));
}
ll SetBit0(ll n,int i)
{
    return (n&~(1ll<<i));
}
int F_X(int n)
{
    int mod = n % 4;
    if (mod == 0)return n;
    else if (mod == 1) return 1;
    else if (mod == 2)return n + 1;
    else if (mod == 3)return 0;
}
const ll MOD=1e9+7;
void Suii()
{
    int n,m;cin>>n>>m;
    ll op=F_X(n-1),ans=n;
    ll p=0;
    if(op==m)
    {
        cout<<ans<<enl;
        return;
    }
    for(int i=0;i<32;i++)
    {
        if(GetBit(op,i)&&!GetBit(m,i))p= SetBit1(p,i);
        else if(!GetBit(op,i)&&GetBit(m,i))p= SetBit1(p,i);
    }
    ans++;
    //cout<<p<<enl;
    if(p==n)ans++;
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