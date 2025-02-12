#include <bits/stdc++.h>
#include <ext/rope>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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
#define ordered_set tree<ll,null_type,less<ll>, \
rb_tree_tag,tree_order_statistics_node_update>
vector<ll>a;
bool Yarb(int mid)
{
    deque<ll>dq;vector<ll>ans;
    for(int i=mid;i<sz(a);i++)dq.push_back(a[i]);
    while(!dq.empty())
    {
        ll mn=min(dq.front(),dq.back());
        ans.push_back(mn);
        if(mn==dq.front())dq.pop_front();
        else dq.pop_back();
    }
    return is_sorted(all(ans));
}
void sol() {
    int n;cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll l=0,r=n-1,mid,ans=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(Yarb(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<enl;
}
int main() {
    Fffffffast();
    Fffffffile();
    int T_C= 1;cin>>T_C;
    while (T_C--)sol();
    return 0;
}