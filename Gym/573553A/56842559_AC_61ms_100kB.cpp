#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int)s.size()
void $olve()
{
    string s;
    cin>>s;
    ll ans=0;
    stack<pair<char,int>>st;
    for(int i=0;i<sz(s);i++)
    {
        if(s[i]=='/')st.push({s[i],i});
        else if(s[i]=='\\')
        {
            ans++;
            ans+=i-st.top().second-1;
            st.pop();
        }
    }
    cout<<ans<<enl;
}
void F_F()
{
    cin.tie(0)->sync_with_stdio(0);
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