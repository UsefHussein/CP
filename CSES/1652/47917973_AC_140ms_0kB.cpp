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
   int n,q;cin>>n>>q;
   vector<vector<ll>>a(n+1,vector<ll>(n+1)),b(n+1,vector<ll>(n+1));
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           char ch;cin>>ch;
           if(ch=='*')a[i][j]=1;
       }
   }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)b[i][j]=b[i][j-1]+a[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)b[j][i]+=b[j-1][i];
    }
    while(q--)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<b[x2][y2]-b[x2][y1-1]-b[x1-1][y2]+b[x1-1][y1-1]<<enl;
    }
}
int main() {
    fffffffast();
    fffffffile();
    int t = 1;//cin>>t;
    while (t--)sol();
    return 0;
}