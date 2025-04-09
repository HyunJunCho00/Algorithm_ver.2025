#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        double t;cin>>t;
        cout<<"$"<<fixed<<setprecision(2)<<t*0.8<<'\n';
    }
    return 0;
}
