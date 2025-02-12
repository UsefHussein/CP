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
const ll MOD=1e9+7;
void Suii()
{
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<n-1;i++)
    {
        if((s[i]=='a'&&s[i+1]=='b')||(s[i+1]=='a'&&s[i]=='b'))
        {
            cout<<i+1<<" "<<i+2<<enl;
            return;
        }
    }
    cout<<-1<<" "<<-1<<enl;
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