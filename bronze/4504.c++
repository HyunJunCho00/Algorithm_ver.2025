#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    while(1)
    {
        int a;cin>>a;
        if(!a)break;
        if (a%n)
            cout<<a<<" is NOT a multiple of "<<n<<".\n";
        else
            cout<<a<<" is a multiple of "<<n<<".\n";
    }
    return 0;
}
