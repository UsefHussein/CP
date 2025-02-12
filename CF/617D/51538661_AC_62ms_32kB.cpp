#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double  dd;
#define enl "\n"
#define F first
//#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
void Suii()
{
   ll x1,x2,x3;
   ll y1,y2,y3;
   cin>>x1>>y1>>x2>>y2>>x3>>y3;
   if((x1==x2)&&(x2==x3)&&(y1==y2)&&(y2==y3))cout<<0;
   else if(((x1==x2)&&(x2==x3))||((y1==y2)&&(y2==y3)))cout<<1;
   else if(((x1==x2)||(x2==x3)||(x1==x3))&&
   ((y1==y2)||(y2==y3)||(y1==y3)))cout<<2;
   else if((x1==x2)&&(((y3>y2)&&(y3>y1))||((y3<y2)&&(y3<y1))))cout<<2;
   else if((x3==x2)&&(((y1>y2)&&(y1>y3))||((y1<y2)&&(y1<y3))))cout<<2;
   else if((x3==x1)&&(((y2>y3)&&(y2>y1))||((y2<y1)&&(y2<y3))))cout<<2;
   else if((y1==y2)&&(((x3>x2)&&(x3>x1))||((x3<x2)&&(x3<x1))))cout<<2;
   else if((y3==y2)&&(((x1>x2)&&(x1>x3))||((x1<x2)&&(x1<x3))))cout<<2;
   else if((y3==y1)&&(((x2>x3)&&(x2>x1))||((x2<x1)&&(x2<x3))))cout<<2;
   else cout<<3;
}
void Fast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void File()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int32_t main()
{
    Fast();
    File();
    //freopen("equal.in", "r", stdin);
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}