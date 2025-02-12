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
int cn=1;string s;pair<ll,ll>ans;
bool  Valid(int mid)
{
    ll mp[10]={0};ll l=0,r=mid,cnt=0;
    bool bo=1;
    for(int i=0;i<mid;i++) {
        if (i < mid - 1 && s[i] == '1' && s[i + 1] == '0')cnt++;
        mp[s[i] - '0']++;
    }
    for(int i=2;i<=9;i++)if(!mp[i])bo=0;
    ans={l+1,r};
    //for(int i=0;i<=9;i++)cout<<mp[i]<<" "<<i<<enl;
    if(cnt&&bo&&mp[1]>1&&mp[0]>1)return 1;
    while(r<sz(s))
    {
        if(s[l]=='1'&&s[l+1]=='0')cnt--;
        mp[s[l] - '0']--;
        if(r<sz(s)-1&&s[r]=='1'&&s[r+1]=='0')cnt++;
        mp[s[r] - '0']++;
        bo=1;
        for(int i=2;i<=9;i++)if(!mp[i])bo=0;
        ans={l+2,r+1};
        //for(int i=0;i<=9;i++)cout<<mp[i]<<" "<<i<<enl;
        if(cnt&&bo&&mp[1]>1&&mp[0]>1)return 1;
        l++,r++;
    }
    return 0;
}
void Suii() {
     /*ll mp[11]={0};
     cin>>s;
     for(int i=0;i<sz(s);i++)
    {
        if(i<sz(s)-1&&!mp[10]&&s[i]=='1'&&s[i+1]=='0')mp[10]++,i++;
        else mp[s[i]-'0']++;
    }
     for(int i=0;i<=10;i++)
    {
        if(!mp[i])
        {
            cout<<"Case "<<cn<<": "<<"NO"<<enl;cn++;
            return;
        }
        mp[i]=0;
    }
     cout<<"Case "<<cn<<": "<<"YES ";
     ll l=12,r=sz(s),mid,Ans_l=1,Ans_r=sz(s);
     while(l<=r)
     {
         mid=(l+r)/2;
         //cout<<mid<<" "<<Valid(mid)<<enl;
         if(Valid(mid))
         {
             Ans_l=ans.F;
             Ans_r=ans.S;
             r=mid-1;
         }
         else l=mid+1;
     }
     cout<<Ans_l<<" "<<Ans_r<<enl;
     cn++;*/
     ll a,b,c;cin>>a>>b>>c;
     if(a+b==c)cout<<"YES";
     else if(a+c==b)cout<<"YES";
     else if(c+b==a)cout<<"YES";
     else cout<<"NO";
     cout<<enl;
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
    cin >> T_C;
    while (T_C--)Suii();
    return 0;
}