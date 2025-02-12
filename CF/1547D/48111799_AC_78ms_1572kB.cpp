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
ll GetBit(int n,int i)
{
    return (n>>i)&1;
}
ll SetBit1(int n,int i)
{
    return (n|(1<<i));
}

void sol() {
  int n;cin>>n;
  vector<ll>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  cout<<"0 ";
  for(int i=1;i<n;i++)
  {
      ll p=a[i]|a[i-1],op=0;
      for(int j=0;j<32;j++)
      {
          if(GetBit(a[i],j)!= GetBit(p,j)) {
              op = SetBit1(op, j);
          }
      }
      a[i]=p;
      cout<<op<<" ";
  }
  cout<<enl;
}
int main() {
    Fffffffast();
    Fffffffile();
    int T_C= 1;cin>>T_C;
    while (T_C--)sol();
    return 0;
}