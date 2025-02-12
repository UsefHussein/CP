#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define F first
#define S second
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
#define rall(x)  x.rbegin(), x.rend()
void Suii()
{
    vector<string>a;
    int n;cin>>n;
    while(n--)
    {
        string s;cin>>s;
        vector<string>ss;
        ll m=sz(s);
        while(m--)
        {
            s.push_back(s[0]);
            s.erase(s.begin());
            ss.push_back(s);
        }
        sort(rall(ss));
        bool bo=0;
        if(sz(a)) {
            for (int i=0;i<sz(ss);i++)
            {
                if(a.back()>=ss[i])
                {
                    a.push_back(ss[i]);
                    bo=1;
                    break;
                }
            }
            if(!bo)
            {
                cout<<"NO";
                return;
            }
        }
        else a.push_back(ss[0]);
    }
    cout<<"YES";
}
void Fast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void File() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main() {
    Fast();
    File();
    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}