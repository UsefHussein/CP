#include<bits/stdc++.h>
#define enl "\n"
typedef long long ll;
typedef double dd;
using namespace std;
#define sz(x)  x.size()
#define all(x)  x.begin(), x.end()
const ll r = 2*(1e5+10);
void fffffffast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void fffffffile() {
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
int main() {
    fffffffast();
    fffffffile();
    ll n;
    cin>>n;
    cout<<n*(n+1)/2;
    return 0;
}