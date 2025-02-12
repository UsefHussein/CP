#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long


void $olve()
{
    int n;
    cin>>n;
    string s,m;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='U'&&s[i+1]=='R')
            m+='D',i++;
        else if(s[i]=='R'&&s[i+1]=='U')
            m+='D',i++;

        else
            m+=s[i];
    }
    cout<<m.size()<<endl;
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