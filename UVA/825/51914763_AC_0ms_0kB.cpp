#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(n) int(n.size())
using namespace std;
using namespace __gnu_pbds;
const ll N=1e2+7;
int mod=998244353;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
void FASTCODE() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void File() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("jobs.in", "r", stdin);
    //freopen("output.in", "w", stdout);
#endif
}
vector<vector<ll>>dp;
vector<vector<int>>v;
int n,m;
ll calc(int i,int j){
    if(i>n||j>m)return 0;
    if(v[i][j])return 0;
    if(i==n&&j==m)return 1;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    ret=calc(i+1,j);
    ret+=calc(i,j+1);
    return ret;
}
void solution() {
    int t;
    cin >> t;
    for(int k=1;k<=t;k++) {
        cin >> n >> m;
        v = vector<vector<int>>(n + 1, vector<int>(m + 1));
        dp = vector<vector<ll>>(n + 5, vector<ll>(m + 5, -1));
        cin.ignore();
        for (int i = 0; i < n; i++) {
            string str;
            getline(cin, str);
            stringstream ss(str);
            int x;
            vector<int> temp;
            while (ss >> x) {
                temp.push_back(x);
            }
            for (int j = 1; j < sz(temp); j++) {
                v[temp[0]][temp[j]] = 1;
            }
        }
        cout << calc(1, 1)<<endl;
        if(k!=t){
            cout << '\n';
        }
    }
}
int32_t main() {
    FASTCODE();
    File();
    int t=1;
    //cin >> t;
    for(int i=1;i<=t;i++) {
        //cout << "Case #"<<i<<": ";
        solution();
        //cout << '\n';
    }
    return 0;
}