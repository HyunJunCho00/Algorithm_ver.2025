#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,a;cin>>n;
    for(int i=0;i<9;i++)
    {
        cin>>a;n-=a;
    }
    cout<<n;
    return 0;
}
