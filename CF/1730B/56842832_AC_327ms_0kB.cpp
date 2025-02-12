#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define ll long long
#define sz(s) (int)s.size()
vector<int>a,b;
double Calc(double mid)
{
    double long sum = 0;
    for (int i = 0; i <sz(a); i++)sum=max(sum,fabsl(a[i]-mid)+b[i]);
    return sum;
}
void ternarySearch(double l, double r)
{
    double ans=0;
    for(int i=0;i<200;i++)
    {
        double mid1 = l + (r - l) / 3.0;
        double mid2 = r - (r - l) / 3.0;
        double c1= Calc(mid1);
        double c2= Calc(mid2);
        ans=min(mid1,mid2);
        if(c1<c2)r=mid2;
        else if(c1>c2) l=mid1;
        else  {
            l = mid1;
            r = mid2;
        }
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
}
\
void $olve()
{
    int n;
    cin >> n;
    a=b=vector<int>(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    ternarySearch(0.0,1e8);
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