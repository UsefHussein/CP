#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double sum=0;
    for(int i=0;i<12;i++)
    {
        double k;cin>>k;
        sum+=k;
    }
    cout<<"$"<<sum/12.0<<endl;
    return 0;
}