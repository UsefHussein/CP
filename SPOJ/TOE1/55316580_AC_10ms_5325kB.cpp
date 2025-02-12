#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define S second
#define F first

const int N=3;

char a[N][N];

string x_o;

bool Ifex(string o)
{
    bool flag=false;
    int id=0;
    for(int i=0;i<N;i++)
        for (int j=0;j<N;j++)a[i][j]=o[id++];

    // vertical
    if(a[0][0]==a[0][1]&&a[0][0]==a[0][2]&&a[0][2]!='.')flag=true;
    if(a[1][0]==a[1][1]&&a[1][0]==a[1][2]&&a[1][2]!='.')flag=true;
    if(a[2][0]==a[2][1]&&a[2][0]==a[2][2]&&a[2][2]!='.')flag=true;
    // horizontal
    if(a[0][0]==a[1][0]&&a[0][0]==a[2][0]&&a[2][0]!='.')flag=true;
    if(a[0][1]==a[1][1]&&a[0][1]==a[2][1]&&a[2][1]!='.')flag=true;
    if(a[0][2]==a[1][2]&&a[0][2]==a[2][2]&&a[2][2]!='.')flag=true;
    // diagonal
    if(a[0][0]==a[1][1]&&a[0][0]==a[2][2]&&a[2][2]!='.')flag=true;
    if(a[0][2]==a[1][1]&&a[0][2]==a[2][0]&&a[2][0]!='.')flag=true;

    return flag;
}

void bfs()
{
    queue<pair<int,string>> q;
    q.push({0,"........."});
    while(!q.empty())
    {
        pair<int,string> p = q.front();
        q.pop();
        if(x_o==p.S)return void(cout<<"yes"<<enl);
        if(Ifex(p.S))continue;
        for(int i=0;i<N*N;i++)
        {
            if(p.S[i]!='.')continue;
            if(!p.F)p.S[i]='X';
            else p.S[i]='O';
            if(p.S[i]!=x_o[i])
            {
                p.S[i]='.';
                continue;
            }
            q.push({p.F^1,p.S});
            p.S[i]='.';
        }
    }
    cout<<"no"<<enl;
}

void $olve()
{
    for(int i=0;i<N;i++)
    {
        string x;cin>>x;
        x_o+=x;
    }
    bfs();
    x_o.clear();
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
    cin>>T;
    while(T--)$olve();
    return 0;
}