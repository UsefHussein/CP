#include <bits/stdc++.h>
#include <ext/rope>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<ll,null_type,less<ll>, \
rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef double dd;
#define enl "\n"
#define sz(x)  ll(x.size())
#define F first
#define S second
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
void Fffffffast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void Fffffffile() {
    //freopen("median.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
void sol() {
    int n;string s;
    cin >> n >> s;
    ll c = 0, r = n,Cnt_l=0,Cnt_r;
    deque<char>dq;
    for (int i = 0; i < n; i++)
    {
        dq.push_back(s[i]);
        s[i]==')'?Cnt_l++:Cnt_r++;
        if(sz(dq)==2)
        {
           /* for(auto i:dq)cout<<i<<" ";
            cout<<enl;*/
            if((dq.back()==')'&&dq.front()=='(')||(dq.back()==')'&&dq.front()==')')||(dq.back()=='('&&dq.front()=='('))
            {
                c++,r-=2;
                dq.clear();Cnt_l=0,Cnt_r=0;
            }
        }
        else if(sz(dq)>2)
        {
            if((Cnt_r==2&&dq.back()=='('&&dq.front()=='(')||(Cnt_l==2&&dq.back()==')'&&dq.front()==')')) {
                c++, r -= sz(dq);dq.clear();
                Cnt_r=0,Cnt_l=0;
            }
        }
    }
    cout<<c<<" "<<r<<enl;
}
int main() {
    Fffffffast();
    Fffffffile();
    int T_C= 1;cin>>T_C;
    while (T_C--)sol();
    return 0;
}