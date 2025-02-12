#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

void $olve()
{
    string s;
    cin>>s;
    int ans=0;
    while(1)
    {
        if(s[0] == '0')break;
        int u=0;
        for(int i=s.length()-1;i>=0;i--)
        {
           u=max(s[i]-'0',u);
        }
        if(u==0)
            break;
        int num=stoi(s)-u;
        s=to_string(num);
        ans++;
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
    int T = 1;//cin>>T;
    while(T--)$olve();
    return 0;
}