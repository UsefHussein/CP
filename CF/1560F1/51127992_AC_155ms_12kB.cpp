#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double  dd;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
int nn,n;
set<ll>st;
void All_sub(string s,string i,string j)
{
    if(sz(s)==10)return;
    if(sz(s)<=9)
    {
        //cout<<s<<enl;
        if(sz(s)&&s[0]!='0')
        {
           st.insert(stoi(s));
        }
    }
    All_sub(s+i,i,j);
    All_sub(s+j,i,j);
}
void IF1()
{
    set<ll>oo;
    nn=sz(to_string(n));
    for(int i=0;i<=9;i++)
    {
        ll op=0,cnt=0;
        while(1)
        {
            op*=10;
            op+=i;
            cnt++;
            oo.insert(op);
            if(cnt==(nn+1))break;
        }
    }
    cout<<*oo.lower_bound(n)<<enl;
}
void Suii()
{
    ll l;
    cin>>n>>l;
    if(l==1)IF1();
    else
    {
        cout<<*st.lower_bound(n)<<enl;
    }
   // for(auto i:st)cout<<i<<enl;
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
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            All_sub("", to_string(i), to_string(j));
        }
    }
    st.insert(ll(1e9));
    int T_C =1;
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}