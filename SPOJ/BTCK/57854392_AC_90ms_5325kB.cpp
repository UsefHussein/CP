#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

vector<int>ans,v,a,b;
bool bo=0;
int m;
void rec(int i,int k)
{
    if(k>m||bo)return;
    if(i==10)
    {
        bo=1;
        for(auto i:b)
            cout<<i<<" ";
        cout<<enl;
        return;
    }
    for(int j=0;j<=9;j++)
    {
        if(v[j])continue;
        v[j]=1;
        b.push_back(j);
        rec(i+1,k+j*a[i]);
        b.pop_back();
        v[j]=0;
    }
}
void $olve()
{
    a.resize(10);
    v.resize(10);
    for(int i=0;i<10;i++)
        cin>>a[i];

    cin>>m;
    rec(0,0);
    if(!bo)cout<<-1<<enl;
    bo=0;
    b.clear();
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