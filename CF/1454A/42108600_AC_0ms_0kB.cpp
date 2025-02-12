#include<bits/stdc++.h>
#include <set>
#include <map>
#define enl "\n"
typedef long long ll;
typedef double dd;
//set<int,greater<int>>d;
//priority_queue<ll,vector<ll>,greater<ll>>q;
#define all(x)  x.begin(), x.end()
using namespace std;
const ll r = 1e5 + 10;
ll poow(int a,int b)
{
    ll sum=1;
    for(int i=1;i<=b;i++)
    {
        sum*=a;
    }
    return sum;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    //cout<<fixed<<setprecision(6);
    //A->65  Z->90
    //a->97  z->122
    int t;
    cin>>t;
    while(t--){
   int n;
   cin>>n;
   deque<ll>q;
   if(n%2!=0)
   {
       for(int i=n;i>=(n/2)+2;i--)
       {
           cout<<i<<" ";
       }
        for(int i=1;i<=(n/2);i++)
       {
           cout<<i<<" ";
       }
       cout<<n/2+1;
   }
   else
   {

       for(int i=n;i>=(n/2)+1;i--)
       {
           cout<<i<<" ";
       }
        for(int i=1;i<=(n/2);i++)
       {
           cout<<i<<" ";
       }
   }
   cout<<enl;
    }

    return 0;

}
