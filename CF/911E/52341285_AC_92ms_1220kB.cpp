#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define enl "\n"
#define sz(x)  ll(x.size())
#define all(x)  x.begin(), x.end()
void Suii()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(k), mp(n + 2);
    mp[0] = 1;
    for (int i = 0; i < k; i++)cin >> a[i], mp[a[i]] = 1;
    stack<ll> st;
    int Sort = 1;
    for (int i = 0; i < k; i++) {
        while (!st.empty()) {
            if (st.top() == Sort) {
                Sort++;
                st.pop();
            } else break;
        }
        if (a[i] == Sort)Sort++;
        else if (st.empty() || a[i] < st.top())st.push(a[i]);
        else return void(cout << -1);
    }
    for (auto i: a)cout << i << " ";
    sort(all(a));
    a.push_back(n);
    for(int i=0;i<=k;i++)
    {
        ll op=a[i];
        while(1)
        {
            if(op==0||(i>0&&op==a[i-1]))break;
            if(!mp[op])cout<<op<<" ";
            op--;
        }
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
int32_t main()
{
    F_F();

    int T_C =1;
    //cin >> T_C;
    while (T_C--)Suii();
    return 0;
}