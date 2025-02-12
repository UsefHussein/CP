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
int mn=10,k;
string s;
void Rec(string h)
{
    if(sz(h)==k)
    {
        ll ind=0,Cnt_Ev=0,Cnt_Od=0;
        string New=s;
        for(int i=0;i<10;i++)if(New[i]=='?')New[i]=h[ind++];
        for(int i=0;i<10;i++)
        {
            if((i+1)&1)Cnt_Od+=New[i]=='1';
            else Cnt_Ev+=New[i]=='1';
            ll op=(10-(i))/2;
            ll op2=(10-(i+1))/2;
            //cout<<Cnt_Ev<<" "<<Cnt_Od<<" "<<op<<" "<<op2<<enl;
            if(Cnt_Ev+op<Cnt_Od){mn=min(mn,i+1);}
            if(Cnt_Od+op2<Cnt_Ev){mn=min(mn,i+1);}
        }
        return;
    }
    Rec(h+'0');
    Rec(h+'1');
}
void Suii()
{
    cin>>s;
    k=count(all(s),'?');
    Rec("");
    cout<<mn<<enl;
    mn=10;
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
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}