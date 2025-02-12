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
bool pl(string s)
{
    string h=s;
    reverse(all(s));
    if(s==h)return 1;
    else return 0;
}
int main()
{
    fffffffast();
    fffffffile();
    string s;
    cin>>s;
    if(pl(s))
    {
        cout<<"Yes";
        return 0;
    }
    int c=0;
    for(int i=sz(s)-1;i>=0;i--)
    {
        if(s[i]=='0')c++;
        else break;
    }
    if(!c)
    {
        cout<<"No";
        return 0;
    }
    else
    {
        string h="";
        while(c--)
        {
            h+='0';
        }
        h+=s;
        if(pl(h))
        {
            cout<<"Yes";
        }
        else cout<<"No";
    }
    return 0;

}