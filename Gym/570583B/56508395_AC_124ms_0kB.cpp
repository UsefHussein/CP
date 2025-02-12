#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

void $olve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s.size()%3!=1)
    {
        for(int i=0;i<s.size();i++)
        {
            cout<<s[i];
            if(i==s.size()-1)break;
            if((i+1)%3==0)cout<<"-";
        }
    }
    else
    {
        cout<<s[0]<<s[1]<<"-";
        int o=1;
        for(int i=2;i<s.size();i++)
        {
            if(o%3==0)cout<<"-";
            cout<<s[i];
            o++;
        }
    }
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