
#include<bits/stdc++.h>
#define enl "\n"
typedef long long ll;
typedef double dd;
using namespace std;
#define sz(x)  x.size()
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
    deque<ll>pip;
    int t;
    cin>>t;
    bool bo=0;
    while(t--)
    {
        string s;
        cin>>s;
        if(s=="push_back")
        {
            int n;
            cin>>n;
            if(bo) pip.push_front(n);
           else  pip.push_back(n);
        }
        else if(s=="toFront")
        {
            int n;
            cin>>n;
            if (bo)pip.push_back(n);
            else  pip.push_front(n);
        }
        else if(s=="reverse"&&!pip.empty()&&bo)bo=0;
        else if(s=="reverse"&&!pip.empty())bo=1;
        else if(s=="back")
        {
            if(pip.empty())cout<<"No job for Ada?";
            else if(bo)
            {
                cout<<pip.front();
                pip.pop_front();
            }
            else
            {
                cout<<pip.back();
                pip.pop_back();
            }
            cout<<enl;
        }
        else if(s=="front")
        {
            if(pip.empty())cout<<"No job for Ada?";
            else if(bo)
            {
                cout<<pip.back();
                pip.pop_back();
            }
            else
            {
                cout<<pip.front();
                pip.pop_front();
            }
            cout<<enl;
        }
    }
    return 0;
}


