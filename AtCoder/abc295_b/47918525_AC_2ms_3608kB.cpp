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
    ll n,m;cin>>n>>m;
    vector<vector<char>>a(n+1,vector<char>(m+1)),ans(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            ans[i][j]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(isdigit(a[i][j]))
            {
                ll l=i,op=a[i][j]-'0',st=i;
                while(op--)
                {
                    for(int c=j;c<=min(j+op+1,m);c++)ans[l][c]='.';
                    for(int c=max(1ll,j-op-1);c<=j;c++)ans[l][c]='.';
                    l++;
                    if(l>n)break;
                }op=a[i][j]-'0';
                while(op--)
                {
                    for(int c=j;c<=min(j+op+1,m);c++)ans[st][c]='.';
                    for(int c=max(1ll,j-op-1);c<=j;c++)ans[st][c]='.';
                    st--;
                    if(st<1)break;
                }
                if(l<=n)ans[l][j]='.';
                if(st>=1)ans[st][j]='.';
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<ans[i][j];
        }
        cout<<enl;
    }
}
int main() {
    fffffffast();
    fffffffile();
    int t = 1;//cin>>t;
    while (t--)sol();
    return 0;
}