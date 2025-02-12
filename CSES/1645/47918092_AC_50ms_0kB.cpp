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
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
void fffffffast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void fffffffile() {
    //freopen("median.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
ll GetBit(int n,int i)
{
    return (n>>i)&1;
}
ll SetBit1(int n,int i)
{
    return (n|(1<<i));
}
ll SetBit0(int n,int i)
{
    return (n&~(1<<i));
}
void sol() {
   int n;cin>>n;
   vector<ll>a(n);
   for(int i=0;i<n;i++)cin>>a[i];
   stack<pair<ll,ll>>sp;
    for(int i=0;i<n;i++)
    {
        while(!sp.empty()&&sp.top().first>=a[i])sp.pop();
        if(!sp.empty())cout<<sp.top().second+1<<" ";
        else cout<<"0 ";
        sp.push({a[i],i});
    }
}
int main() {
    fffffffast();
    fffffffile();
    int t = 1;//cin>>t;
    while (t--)sol();
    return 0;
}