#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
vector<ll>a;set<ll>st;int n;
bool Valid(int mid)
{
    bool bo=1;map<ll,ll>mp;
    for(auto i:a)mp[i]++;
    for(int i=0;i<mid;i++)mp[a[i]]--;
    for(auto i:st)
    {
        if(mp[i]>1) {
            bo = 0;
            break;
        }
    }
    if(bo)return 1;
    ll l=0,r=mid;
    while(r<n)
    {
        mp[a[r]]--,mp[a[l]]++;bo=1;
        for(auto i:st)
        {
            if(mp[i]>1) {
                bo = 0;
                break;
            }
        }
        if(bo)return 1;
        r++,l++;
    }
    return 0;
}
void Suii() {
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i],st.insert(a[i]);
    ll l=0,r=n,mid,ans=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(Valid(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans;
}
void Fast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void File() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main() {
    Fast();
    File();
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}