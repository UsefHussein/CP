#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int) (s).size()
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
namespace __gnu_pbds
{
    typedef tree<ll, null_type, less_equal< ll>,rb_tree_tag,
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
    ordered_set st;
    ll q,n;
    cin>>q>>n;
    map<ll,ll>mp;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            ll id,x;
            cin>>id>>x;
            if(mp.count(id)) {
                myerase(st,mp[id]);
            }
            mp[id]+=x;
            st.insert(mp[id]);
        }
        else if(t==2)
        {
            ll x;
            cin>>x;
            cout<<sz(st)-st.order_of_key(x+1)<<endl;
        }
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

signed main()
{
    F_F();
    int T = 1;
    //cin>>T;
    while(T--)$olve();
    return 0;
}