#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    long long int a,b;cin>>a>>b;
    if (a>b)swap(a,b);
    long long int as=a<0?-(a-1)*a/2:(a-1)*a/2;
    long long int bs=b<0?(b+1)*b/2:(b+1)*b/2;
    cout<<(as<0?bs+as:bs-as)<<'\n';
    return 0;
}
