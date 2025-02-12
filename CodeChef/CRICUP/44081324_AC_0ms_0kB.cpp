
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
int main()
{
    fffffffast();
    fffffffile();
    int t,l=1;
    cin>>t;
    while(t--)
    {
        ll n,m,k,c=0;
        cin>>n>>m>>k;
        n=abs(n-m);
        cout<<((n<=k)?"YES":"NO")<<enl;
    }
    return 0;
}


