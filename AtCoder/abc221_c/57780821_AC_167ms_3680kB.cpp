#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long



void $olve()
{
    string s;
    cin >> s;
    ll ans=0;
    sort(s.begin(), s.end());
    do
    {
        for(int j=0;j<s.size();j++)
        {
            bool bo=0;
            string t="",k="";
            for (int i = 0; i < j; i++)
            {
                if(i==0&&s[i]=='0')bo=1;
                t+=s[i];
            }
            for (int i = j; i < s.size(); i++)
            {
                if(i==j&&s[i]=='0')bo=1;
                k+=s[i];
            }
            if(!bo&&t.size()&&k.size())
            ans=max(ans,stoll(t)*stoll(k));
        }
    }while(next_permutation(s.begin(), s.end()));
    cout << ans << endl;
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