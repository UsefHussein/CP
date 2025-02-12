#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e2+1,Mod=1e8;
void Suii()
{
    int n;cin>>n;
    if(n&1)
    {
        cout<<2<<enl<<n/2<<" "<<(n+1)/2;
    }
    else
    {
        cout<<n-1<<enl;
        for(int i=1;i<n-1;i++)cout<<1<< " " ;
        cout<<2<<" ";
    }
}
void F_F()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
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