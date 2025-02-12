#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=3e3+5;
ll n,m;
vector<vector<ll>>dp,a;
ll Dp(int i,int j)
{
    if(i>=n||j>=m||!a[i][j])return 0;
    if(i==n-1&&j==m-1)return 1;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    return ret=(Dp(i+1,j)+Dp(i,j+1));
}
void Suii()
{
    int t;cin>>t;
    for(int u=0;u<t;u++) {
        cin >> n >> m;
        dp.assign(n + 10, vector<ll>(m+10, -1));
        a.assign(n + 10, vector<ll>(m+10, 1));
        cin.ignore();
        for (int i = 0; i < n; i++) {
            string st;
            getline(cin,st);
            stringstream s(st);
            int Word,l=0;
            while (s >> Word)
            {
                if(l!=0)a[i][Word-1]=0;
                l++;
            }
        }
        //for(int i=0;i<n;i++,cout<<enl)for(int j=0;j<m;j++)cout<<a[i][j]<< " ";
        cout << Dp(0, 0) <<enl ;
        if(u!=t-1)cout<<enl;
    }
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
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}