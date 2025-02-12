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
set<string>ans;
void All_sub(string &s,int l ,int r)
{
    if(l==r)
    {
        ans.insert(s);
        return;
    }
    for(int i=l;i<=r;i++)
    {
        swap(s[i],s[l]);
        All_sub(s,l+1,r);
        swap(s[i],s[l]);
    }
}
void Suii()
{
    string s;
    cin>>s;
    All_sub(s,0,sz(s)-1);
    cout<<sz(ans)<<enl;
    for(auto i:ans)cout<<i<<enl;
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
int32_t main()
{
    Fast();
    File();
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}