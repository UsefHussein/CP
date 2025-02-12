#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

char a[9][9];
bool viscol[10], visd1[100],visd2[100];
ll ans=0;
void rec(int i)
{
    if(i==8)
    {
        ans++;
        return;
    }
    for(int j=0;j<8;j++)
    {
        if(viscol[j]||visd1[i+j]||visd2[i-j+8-1]||a[i][j]=='*')continue;
        viscol[j]=visd1[i+j]=visd2[i-j+8-1]=1;
        rec(i+1);
        viscol[j]=visd1[i+j]=visd2[i-j+8-1]=0;
    }
}
void $olve()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            cin>>a[i][j];

    rec(0);
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
    int T = 1;// cin>>T;
    while(T--)$olve();
    return 0;
}