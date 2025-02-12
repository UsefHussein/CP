#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N=2e5+1;

bool vis[N];
vector<pair<int,int>> a;
int n;
vector<int> v;
bool valid(int p)
{
    memset(vis,false,sizeof(vis));
    vector<int>ans={1,p};
    vis[p]=true;
    vis[1]=true;
    int ind=0;
    while(1)
    {
        if(ans.size()==n)break;
        pair<int,int> o=a[ans[ind]];
        if(!vis[o.first])ans.push_back(o.first);
        if(!vis[o.second])ans.push_back(o.second);
        ind++;
        vis[o.first]=true;
        vis[o.second]=true;
    }
    v=ans;
    int oo=1,oo1=2;
    for(int i=0;i<n;i++)
    {
        int mn=min(ans[oo],ans[oo1]);
        int mx=max(ans[oo++],ans[oo1++]);
        int mnn=min(a[ans[i]].first,a[ans[i]].second);
        int mxx=max(a[ans[i]].first,a[ans[i]].second);
        if(mxx!=mx||mn!=mnn)
        {
            return 0;
        }
        if(oo>=n)oo-=n;
        if(oo1>=n)oo1-=n;
    }
    return 1;
}
void $olve()
{
    cin>>n;
    a=vector<pair<int,int>>(n+2);
    for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
    //cout<<valid(a[1].first)<<" "<<valid(a[1].second)<<endl;
    if(valid(a[1].first)) {
        for(auto i:v)cout<<i<<" ";
    }
    else if(valid(a[1].second)) {
        for(auto i:v)cout<<i<<" ";
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