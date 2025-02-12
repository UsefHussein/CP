#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

ll op(int sum) {
    if(sum>=500)return sum-100;
    return sum;
}
void $olve()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans1=op(a+b+c);
    ll ans2=op(a+b)+op(c);
    ll ans3=op(a+c)+op(b);
    ll ans4=op(b+c)+op(a);
    ll ans5=op(c)+op(a)+op(b);
    cout<<min({ans1,ans2,ans3,ans4,ans5});
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