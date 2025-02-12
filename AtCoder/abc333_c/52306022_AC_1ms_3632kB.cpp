#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e2+1,Mod=1e8;
vector<string>ans;
void Pre(string s)
{
    if(sz(s)>12)return;
    ans.push_back(s);
    Pre('1'+s);
    if(s[0]!='1')Pre('2'+s);
    if(s[0]!='2'&&s[0]!='1')Pre('3'+s);
}
bool Com(string a,string b)
{
    if(sz(a)==sz(b))return a<b;
    return sz(a)<sz(b);
}
void Suii()
{
    Pre("3");
    sort(all(ans), Com);
    int n;cin>>n;
    cout<<ans[n-1];
}
void F_F()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
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