#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e3+2;

vector<int> num;
ll DP[19][11][2][2];
ll call(int pos, int cnt, bool Z,bool Adj)
{
    if(pos == num.size())return 1;
    ll &ret=DP[pos][cnt][Z][Adj];
    if(cnt!=10&&~ret) return ret;
    ll res = 0;
    ll LMT=Adj?num[pos]:9;
    for(int dgt = 0; dgt<=LMT; dgt++)
    {
        if(cnt==dgt&&!Z)continue;
        res+=call(pos+1,dgt,Z&&(!dgt),Adj&&(dgt==LMT));
    }
    return ret = res;
}
ll solve(ll b)
{
    num.clear();
    while(b>0)
    {
        num.push_back(b%10);
        b/=10;
    }
    reverse(all(num));
    memset(DP, -1, sizeof(DP));
    ll res = call(0, 10, 1,1);
    return res;
}
void Suii()
{
    ll a,b;
    cin >> a >> b ;
    ll res = solve(b) - solve(a-1);
    if(!a)res++;
    cout << res << endl;
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