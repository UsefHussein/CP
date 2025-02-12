#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int) (s).size()

void $olve()
{
    string s;
    cin >> s;
    stack<char> st;
    ll ans=0;
    for (int i = 0; i < sz(s); i++)
    {
        if(st.empty()||(st.top()==s[i]))st.push(s[i]);
        else if(s[i]!=st.top()) {
            st.pop();
            ans+=2;
        }
    }
    cout<<ans<<enl;
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