#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
const int N=1e3+2;
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
void myerase(ordered_set &t, int v)
{
    int rank = t.order_of_key(v);
    ordered_set::iterator it = t.find_by_order(rank);
    t.erase(it);
}
void Suii()
{
    int n,m,q;cin>>n>>m>>q;
    char a[n][m];
    int V[n][m];
    ll Cost=0,cnt=1;
    ordered_set st;
    for(int i=0;i<m;i++)for(int j=0;j<n;j++)V[j][i]=cnt++;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='*')
            {
                st.insert(V[i][j]);
                Cost++;
            }
        }
    }
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (a[x][y] == '*')
        {
            myerase(st,V[x][y]);
            Cost--;
            a[x][y]='.';
        }
        else
        {
            Cost++;
            st.insert(V[x][y]);
            a[x][y]='*';
        }
        cout<<sz(st)-st.order_of_key(Cost+1)<<enl;
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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}