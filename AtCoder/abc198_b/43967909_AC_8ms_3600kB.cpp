#include<bits/stdc++.h>
#define enl "\n"
typedef long long ll;
typedef double dd;
using namespace std;
#define sz(x)  x.size()
#define all(x)  x.begin(), x.end()
const ll r = 2*(1e5+10);
void fffffffast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void fffffffile() {
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
bool pal(string s)
{
    string h=s;
    reverse(all(h));
    if(h==s)return 1;
    return 0;
}
int main() {
    fffffffast();
    fffffffile();
    string s;
    cin>>s;
    if(pal(s))
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
    string h="";
    if(c)
    {
        for(int i=0;i<c;i++)
        {
            h+='0';
        }
        h+=s;
    }
    //cout<<h<<" "<<c;
    cout<<((pal(h)&&sz(h)>0)?"Yes":"No");
    return 0;
}