#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
// ordered_set
// headers
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
namespace __gnu_pbds
{
    typedef tree<ll, null_type, less_equal< ll>,rb_tree_tag,
    // change int to any datatype
    // this is ordered_set
    // if you want to use multi ordered_set --> replace less with less_equal
    // replace less with greater if you want to sort it in reverse order
    tree_order_statistics_node_update>
    ordered_set;
    // *st.find_by_order(x) --> value in index x
    // st.order_of_key(x) --> index of first value of x

}
using namespace __gnu_pbds;
void myerase(ordered_set &t, ll v)
{
    ll rank = t.order_of_key(v);
    ordered_set::iterator it = t.find_by_order(rank);
    t.erase(it);
}

void $olve()
{
    int q;cin>>q;
    vector<ll> a(q+5);
    ordered_set st;
    for(int i=1;i<=q;i++)
    {
        int t;cin>>t;
        if(t==1)
        {
            ll x;cin>>x;
            st.insert(x);
            a[i]=x;
        }
        else if(t==2)
        {
            ll x;cin>>x;
            myerase(st, a[x]);
        }
        else if(t==3)
        {
            ll x,y;cin>>x>>y;
            myerase(st, a[x]);
            a[x]+=y;
            st.insert(a[x]);
        }
        else
        {
            ll x;cin>>x;
            cout<<st.order_of_key(a[x])<<enl;
        }

    }
}
void F_F()
{
    cin.tie(0)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
signed main()
{
    F_F();
    int T = 1;//cin>>T;
    while(T--)$olve();
    return 0;
}
