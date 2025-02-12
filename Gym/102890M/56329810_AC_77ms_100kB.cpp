#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) int(s.size())

void $olve()
{
    string s;
    vector<int>mp(10),fr(10);
    cin>>s;
    for(int i=0;i<s.size();i++)fr[s[i]-'0']++;
    for(int i=1;i<=9;i++)cin>>mp[i];
    for(int i=1;i<=9;i++)fr[i]-=mp[i];
    stack<char>ans;
    for(int i=0;i<sz(s);i++)
    {
        if(!fr[s[i]-'0'])
        {
            mp[s[i]-'0']--;
            continue;
        }
        while(sz(ans))
        {
            if(ans.top()>=s[i]||!mp[ans.top()-'0'])break;
            mp[ans.top()-'0']--;
            fr[ans.top()-'0']++;
            ans.pop();
        }
        ans.push(s[i]);
        fr[s[i]-'0']--;
    }
    string ss="";
    while(!ans.empty())
    {
        ss+=ans.top();
        ans.pop();
    }
    for(int i=0;i<sz(ss);i++)
    {
        if(mp[ss[i]-'0'])mp[ss[i]-'0']--,ss[i]='^';
    }
    reverse(ss.begin(),ss.end());
    for(int i=0;i<sz(ss);i++)if(ss[i]!='^')cout<<ss[i];
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