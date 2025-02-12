#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=1e2;

void $olve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=0,cnt=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='1')
        {
            cnt+=2,ans++;
            if(cnt>2)cnt=2;
        }
        else if(cnt)ans++,cnt--;
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