#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=1e2;

void $olve()
{
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(s[0]!=s[1])cout<<s[0];
    else if(s[1]!=s[2]&&s[1]!=s[0])cout<<s[1];
    else if(s[1]!=s[2])cout<<s[2];
    else cout<<-1;
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