#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
void Suii() {
    ll n,x;cin>>n>>x;
    set<ll>b,a;
    for(int i=0;i<n;i++) {
        int y;cin>>y;
        a.insert(y);
        b.insert(y);
    }
    if(x==0)
    {
        cout<<sz(a)<<enl;
        return;
    }
    ll k=2;
    while(k--)
    {
        ll op=*a.rbegin();
        ll mex=0;
        for(int i=1;i<=sz(a);i++)
        {
            if(!a.count(i))
            {
                mex=i;
                break;
            }
        }
        ll k=op+mex;
        if((mex+op)&1)k++;
        k/=2;
        a.insert(k);
        /*for(auto i:a)cout<<i<<" ";
        cout<<enl;*/
    }
   // cout<<sz(a)<<" "<<sz(b)<<" ";
    if(sz(a)-sz(b)==2)cout<<sz(b)+x;
    else if(sz(a)-sz(b)<=1)cout<<sz(a);
    cout<<enl;
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