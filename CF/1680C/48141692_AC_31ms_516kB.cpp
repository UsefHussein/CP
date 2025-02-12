#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
string s;
bool Yarb(int mid)
{
    ll r=0,Cnt_0=0,Cnt_1=0,cnt=count(all(s),'1'),n=sz(s);
    for(int l=0;l<n;l++)
    {
       while(r<n&&Cnt_0<=mid)
       {
           s[r++]=='1'?Cnt_1++:Cnt_0++;
           if(max(Cnt_0,cnt-Cnt_1)<=mid)return 1;
       }
       s[l]=='1'?Cnt_1--:Cnt_0--;
    }
    return max(Cnt_0,cnt-Cnt_1)<=mid;
}
void Suii()
{
    int n;
    cin >>s;
    n=sz(s);
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
    //cout<<Yarb(3);
    cout<<ans<<enl;
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