#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
void Suii() {
  int n,x;cin>>n>>x;
  vector<ll>a(n);ll sum=0;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=1;i<n;i++) sum+=abs(a[i]-a[i-1]);
  ll Mx=*max_element(all(a)),Mn=*min_element(all(a));
  if(Mx<x)sum+=min(2*((x-Mx)),min(abs(a[0]-x),abs(a[n-1]-x)));
  if(Mn>1)sum+=min(2*(Mn-1),min(a[0]-1,a[n-1]-1));
  cout<<sum<<enl;
}
void Fffffffast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void Fffffffile() {
    //freopen("median.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
int main() {
    Fffffffast();
    Fffffffile();
    int T_C = 1;
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}