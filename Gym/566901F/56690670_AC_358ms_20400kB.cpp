#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long

const int N = 2e5 + 5;
vector <vector<int>> divisors(N);
void generate_divisors()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
            divisors[j].push_back(i);
    }
}
void $olve()
{
    generate_divisors();
    int n;
    cin>>n;
    vector<int>mp(N),mx(N,-1),ans(n+1);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(auto k:divisors[x])mp[k]++;
    }
    for(int i=1;i<N;i++)mx[mp[i]]=max(mx[mp[i]],i);
    for(int i=n;i>=1;i--)
    {
        mx[i]=max(mx[i],mx[i+1]);
    }
    for(int i=1;i<=n;i++)cout<<mx[i]<< " ";
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
    //cin>>T;
    while(T--)$olve();
    return 0;
}