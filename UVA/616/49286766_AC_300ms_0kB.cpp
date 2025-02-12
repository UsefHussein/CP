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
//void Suii()
//{
//    int n;cin>>n;
//    vector<ll>a(n),pr(n),su(n),Next_step_from_R(n),Next_step_from_L(n);
//    for(int i=0;i<n;i++)cin>>a[i];
//    for(int i=1;i<n;i++)pr[i]+=pr[i-1];
//    for(int i=n-2;i>=0;i--)su[i]+=su[i+1];
//    stack<ll>st;
//    for(int i=0;i<n;i++) {
//        while (sz(st) && a[st.top()] != a[i])st.pop();
//        if (sz(st))Next_step_from_R[i] = st.top();
//        else Next_step_from_R[i] = -1;
//        st.push(i);
//    }
//    st=stack<ll>();
//    for(int i=n-1;i>=0;i--) {
//        while (sz(st) && a[st.top()] != a[i])st.pop();
//        if (sz(st))Next_step_from_L[i] = st.top();
//        else Next_step_from_L[i] = -1;
//        st.push(i);
//    }
////    for(auto i:Next_step_from_R)cout<<i<<" " ;
////    cout<<enl;
////    for(auto i:Next_step_from_L)cout<<i<<" " ;
////    cout<<enl;
//    for(int i=0;i<n;i++)
//    {
//        ll l=i+1,r=n-1,mid=0;
//        if(l==n)l--;
//        ll ans=-1;
//        while(l<=r&&(mid+i)<n)
//        {
//            mid=(l+r)/2;
//            ll sum=pr[mid+i]-pr[i];
//            if(sum>a[i]&&mid+i!=Next_step_from_R[i+1])
//            {
//                ans=mid;
//                l=mid+1;
//            }
//            else r=mid-1;
//        }
//        l=0,r=i-1,mid=0;
//        if(!l)l++;
//        ans=-1;
//        while(l<=r&&(mid-i)>=0)
//        {
//            mid=(l+r)/2;
//            ll sum=su[mid-i]-su[i];
//            if(sum>a[i]&&mid-i!=Next_step_from_L[i-1])
//            {
//                ans=min(ans,mid);
//                l=mid+1;
//            }
//            else r=mid-1;
//        }
//        cout<<ans<< " ";
//    }
//    cout<<enl;
//}
int n;
void Suii()
{
    while(cin>>n) {
        if(n<0)break;
        ll ans = -1;
        for (int i = sqrt(n)+1; i >= 1; i--) {
            ll k = n;
            ll op = i;
            while (op--) {
                k--;
                if(k%i)break;
                k -= k / i;
            }
            if (k % i == 0) {
                ans = i;
                break;
            }
            shit:;
        }
        //25 coconuts, 3 people and 1 monkey
        if (ans <=1)cout << n << " coconuts, no solution" << enl;
        else cout << n << " coconuts, " << ans << " people and 1 monkey" << enl;
    }
}
void Fast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void File()
{
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