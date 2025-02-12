
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
void fffffffile() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
int main()
{
    fffffffast();
    fffffffile();
    stack<ll>pip;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            int y;
            cin>>y;
            pip.push(y);
        }
        else if(n==2&&!pip.empty())
        {
            pip.pop();
        }
        else if(n==3)
        {
            if(pip.empty())cout<<"Empty!";
            else cout<<pip.top();
            cout<<enl;
        }
    }
    return 0;
}


