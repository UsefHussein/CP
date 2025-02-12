#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
vector<ll>a,b;
bool Valid(int mid,int x,int y)
{
    for(int i=0;i<sz(a);i++)
    {
        ll op=abs(a[i]+b[i]);
        op=abs(op-mid);
        if(mid<y||mid>x)return 0;
    }
    return 1;
}
void Suii() {
    int n,x,y;cin>>n>>x>>y;
    a.resize(n),b.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    ll Mx=LLONG_MIN,Mn=LLONG_MAX;
    for(int i=0;i<n;i++)
    {
        Mx=max(Mx,a[i]-b[i]);
        Mn=min(Mn,a[i]-b[i]);
    }
    cout<<(Mx-Mn<=(x-y)*2?"YES":"NO")<<enl;
}
void Fffffffast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void Fffffffile() {
    //freopen("median.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
int main() {
    Fffffffast();
    Fffffffile();
    int T_C = 1;
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}