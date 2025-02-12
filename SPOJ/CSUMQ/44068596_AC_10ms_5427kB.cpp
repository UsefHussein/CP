
#include<bits/stdc++.h>
#define enl "\n"
typedef long long ll;
typedef double dd;
using namespace std;
#define all(x)  x.begin(), x.end()
#define sz(x)  x.size()
const ll r = 1e5 + 10;
void fffffffast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
/**
  vector<vector<int>>arr(n,vector<int>(n));////2D
 //cout<<fixed<<setprecision(6);
 //set<int,greater<int>>d;
//priority_queue<ll,vector<ll>,greater<ll>>q;
 **/
void fffffffile() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
bool prime(int x){
    if(x < 2)
        return false;

    for(int i = 2 ; i*i <=x ;i++ ){
        if(x%i == 0)
            return false;
    }
    return true;
}
struct po
{
    int x,y,c;
};
int main()
{
    fffffffast();
    fffffffile();
    int n;
    cin>>n;
    vector<ll>a(n+1);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=1;i<n;i++)a[i]+=a[i-1];
    int q;
    cin>>q;
    while (q--)
    {
        int x,y;
        cin>>x>>y;
        if(x==0)cout<<a[y]<<enl;
        else cout<<a[y]-a[x-1]<<enl;
    }
    return 0;
}


