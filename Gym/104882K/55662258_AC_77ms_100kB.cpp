#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long


void $olve()
{
    int n,k;
    cin>>n>>k;
    vector<int>ans(26);
    string s;
    cin>>s;
    for(int i=0;i<k;i++)ans[s[i]-'a']++;
    vector<int>mn=ans;
    int l=0,r=k;
    while(r<n)
    {
        mn[s[r++]-'a']++;
        mn[s[l++]-'a']--;
        if(ans<mn)ans=mn;
    }
    for(int i=0;i<26;i++)
    {
        while(ans[i]--)cout<<char(i+'a');
    }
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