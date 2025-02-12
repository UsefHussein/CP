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
bool prime(ll x) {
    if (x < 2)
        return false;

    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}
void Suii() {
    ll n,a;vector<ll>ans;
    cin >> n>>a;
    if (n == 1)
    {
        cout<<a;
        return;
    }
    for(int i=1;i<=1e6;i++)
    {
        if(prime(i+a))
        {
           ans.push_back(i);
            break;
        }
    }
    for(int i=1;i<=1e6;i++)
    {
        if(prime(i+ans[0]))
        {
            ans.push_back(i);
            break;
        }
    }
    ll ind=0;
    cout<<a<<" ";
    n--;
    while(n--)
    {
        cout<<ans[ind]<<" ";
        ind++;
        if(ind==2)ind=0;
    }
}
void Fast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void File() {
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