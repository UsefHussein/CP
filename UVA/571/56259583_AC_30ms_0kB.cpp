#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
const int t[]={0,1,2,3,4,5};
// fill A 0
// fill B 1
// empty A 2
// empty B 3
// pour A B 4
// pour B A 5
bool vis[1001][1001];
int a,b,n;
struct node {
    int a,b,prev;
    string ans;
};
void bfs()
{
    queue<node> q;
    q.push({0,0,-1,""});
    while(!q.empty())
    {
        node p=q.front();
        q.pop();
        if(p.a==n||p.b==n)
        {
            for(auto i:p.ans)
            {
                if(i=='0')cout<<"fill A";
                if(i=='1')cout<<"fill B";
                if(i=='2')cout<<"empty A";
                if(i=='3')cout<<"empty B";
                if(i=='4')cout<<"pour A B";
                if(i=='5')cout<<"pour B A";
                cout<<enl;
            }
            cout<<"success"<<enl;
            return;
        }
        if(vis[p.a][p.b])continue;
        vis[p.a][p.b]=1;
        for(int i=0;i<6;i++)
        {
            node n={p.a,p.b,p.prev,p.ans};
            if(i!=p.prev)
            {
                if(!i)
                {
                    n.a=a;
                    n.ans+=to_string(i);
                    q.push(n);
                }
                if(i==1)
                {
                    n.b=b;
                    n.ans+=to_string(i);
                    q.push(n);
                }
                if(i==2)
                {
                    n.a=0;
                    n.ans+=to_string(i);
                    q.push(n);
                }
                if(i==3)
                {
                    n.b=0;
                    n.ans+=to_string(i);
                    q.push(n);
                }
                if(i==4)
                {
                    ll mn=min(n.a,b-n.b);
                    n.a-=mn;
                    n.b+=mn;
                    n.ans+=to_string(i);
                    q.push(n);
                }
                if(i==5)
                {
                    ll mn=min(n.b,a-n.a);
                    n.a+=mn;
                    n.b-=mn;
                    n.ans+=to_string(i);
                    q.push(n);
                }
            }
        }
    }
}
void $olve()
{
    while(cin>>a>>b>>n)
    {
        memset(vis,0,sizeof(vis));
        bfs();
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