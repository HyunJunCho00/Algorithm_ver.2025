#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    int s=3;
    for (int i=1;i<n;i++)
        s=s*2-1;
    cout<<s*s<<'\n';
    return 0;
}
