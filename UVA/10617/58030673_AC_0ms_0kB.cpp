#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
#define tashaaaaakoraaah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define int long long
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define el '\n'
const double pi = 3.14159265359;
const int dx[] = { 1,-1,0,0,1,1,-1,-1 };
const int dy[] = { 0,0,-1,1,1,-1,1,-1 };
int mod = 1e9 + 7;
void IN_OU()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
}

const int N=1e5+7;
int n;
string s;
int Dp[61][61];
int dp_ma(int i,int j){
  if(i==j){
    return 1;
  }
  if(i+1==j){
    return 2+(s[i]==s[j]);
  }
  int &ret=Dp[i][j];
  if(~ret){
    return ret;
  }
  ret=0;
  if(s[i]==s[j]){
    ret+=dp_ma(i+1,j-1)+1;
  }
  ret+=dp_ma(i+1,j);
  ret+=dp_ma(i,j-1);
  ret-=dp_ma(i+1,j-1);
  return ret;
}
static void tashakor_RI(){
  cin>>s;
  memset(Dp,-1,sizeof(Dp));
  cout<<dp_ma(0,s.size()-1)<<el;

}
int32_t main()
{
  //!freopen("mex.)in ", "r", stdin);
  IN_OU();
  tashaaaaakoraaah;
  int t=1;
  cin >> t;
  while (t--) {
      tashakor_RI(); 
  }
}