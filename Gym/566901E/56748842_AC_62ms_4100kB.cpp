#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

vector<string>d={"1111110","0110000","1101101",
"1111001","0110011","1011011","1011111",
    "1110000","1111111","1111011"};
const int N=101;
int dp[N][N][N];
int n,x,y;
string s,m;

int Dp(int i,int remx, int remy)
{
    if(i==n)return 1;
    int &ret=dp[i][remx][remy];
    if(~ret) return ret;
    ret=0;
    for(int j=0;j<10;j++)
    {
        if(!i&&!j)continue;
        int op1=0,op2=0;
        for(int k=0;k<7;k++)
        {
            if(d[s[i]-'0'][k]=='0'&&d[j][k]=='1')op2++;
            if(d[m[i]-'0'][k]=='0'&&d[j][k]=='1')op2++;
            if(d[s[i]-'0'][k]=='1'&&d[j][k]=='0')op1++;
            if(d[m[i]-'0'][k]=='1'&&d[j][k]=='0')op1++;
        }
        if(remx+op1<=x&&
           remy+op2<=y)
        {
            ret|=Dp(i+1,remx+op1,remy+op2);
        }
    }
    return ret;
}
void $olve()
{
    cin>>n>>x>>y;
    cin>>s>>m;
    memset(dp,-1,sizeof(dp));
    cout<<(Dp(0,0,0)?"YES":"NO")<<enl;;
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
    cin>>T;
    while(T--)$olve();
    return 0;
}