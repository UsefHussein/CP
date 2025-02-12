#include<bits/stdc++.h>
#define enl "\n"
typedef long long ll;
typedef double dd;
using namespace std;
#define all(x)  x.begin(), x.end()
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
int main()
{
    fffffffast();
    int t;
    cin>>t;
    while(t--) {
        int n,a=0,b=1;
        cin >> n;
        if(n==2)
        {
            cout<<-1<<enl;
        }
        else if(n==1)
        {
            cout<<1<<enl;
        }
        else {
            for (int i = 2; i <= (n * n); i += 2) {
                a++;
                if (i % 2 == 0) {
                    cout << i << " ";
                }
                if (a == n) {
                    cout << enl;
                    a = 0;
                }
            }
            for (int i = 1; i <= (n * n); i += 2) {
                a++;
                if (i % 2 != 0) {
                    cout << i << " ";
                }
                if (a == n) {
                    cout << enl;
                    a = 0;
                }
            }
        }

    }

    return 0;
}