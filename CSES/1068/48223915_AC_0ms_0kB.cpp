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
bool rec(int n)
{
    cout<<n<<" ";
    if(n<=1)return 0;
    if(n&1)rec(n*3+1);
    rec(n/2);
}
void Suii() {
   ll n;cin>>n;
    while(n!=1)
    {
        cout<<n<<" ";
        if(n&1)n=n*3+1;
        else n/=2;
    }
    cout<<1;
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
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}