#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=1e2;
// ordered_set
// headers
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
namespace __gnu_pbds
{
    typedef tree<int, null_type, less<int>,rb_tree_tag,
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
void myerase(ordered_set &t, int v)
{
    int rank = t.order_of_key(v);
    ordered_set::iterator it = t.find_by_order(rank);
    t.erase(it);
}
void $olve()
{
    vector<ordered_set>st(26);
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)st[s[i]-'A'].insert(i+1);
    while(q--)
    {
        string c;
        cin>>c;
        if(c=="COUNT")
        {
            char ch;
            int l,r;
            cin>>ch>>l>>r;
            int it=st[ch-'A'].order_of_key(l);
            int L=0,R=st[ch-'A'].size()-1,ans=-1;
            while(L<=R)
            {
                int mid=(L+R)/2;
                if(*st[ch-'A'].find_by_order(mid)<=r)
                {
                    ans=mid;
                    L=mid+1;
                }
                else R=mid-1;
            }
            if(~ans&&ans>=it)cout<<ans-it+1<<" ";
            else cout<<0<<" ";
        }
        else
        {
            int l,r;
            cin>>l>>r;
            char f1=s[l-1];
            char f2=s[r-1];
            swap(s[l-1],s[r-1]);
            myerase(st[f1-'A'],l);
            myerase(st[f2-'A'],r);
            st[f2-'A'].insert(l);
            st[f1-'A'].insert(r);
        }
    }
    cout<<enl;
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
    cin>>T;
    while(T--)$olve();
    return 0;
}