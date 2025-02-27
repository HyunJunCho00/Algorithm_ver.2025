#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,k,m;cin>>n>>k>>m;
    cout<<(m>=n*k?0:n*k-m)<<'\n';
    return 0;
}
