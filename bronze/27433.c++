#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    long long sum=1;
    while(n)sum*=(n--);
    cout<<sum;
    return 0;
}
