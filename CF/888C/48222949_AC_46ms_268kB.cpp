#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.rbegin(), x.rend()
string s;
bool Yarb(int mid)
{
    vector<ll>mp(125),kp(125);
    for(int i=0;i<mid;i++)mp[s[i]]++,kp[s[i]]=1;
    ll l=0,r=mid;
    while(r<sz(s))
    {
        mp[s[l++]]--;
        mp[s[r++]]++;
        for(int i='a';i<='z';i++) {
            if (kp[i]&&!mp[i])kp[i]=-1;
        }
    }
    for(int i='a';i<='z';i++) {
        if (kp[i]>0)return 1;
    }
    return 0;
}
void Suii() {
    cin>>s;
    ll l=1,r=sz(s),ans=0,mid;
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
    //cout<<Yarb(1);
    cout<<ans;
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
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}