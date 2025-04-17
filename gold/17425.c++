#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
long long int a[1000001];
long long int r[1000001];
int main(void)
{
    fastIO;
    for(int i=2;i<=1000000;i++)a[i]=i+1; a[1]=1;
    for(int n1=2;n1<int(sqrt(1000000))+1;n1++)
    {
        for(int n2=n1;n2<int(1000000/n1)+1;n2++)
        {
            n1!=n2?(a[n1*n2]+=n1+n2):a[n1*n2]+=n1;
        }
    }
    for(int i=1;i<=1000000;i++)r[i]=r[i-1]+a[i];
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;cin>>n;
        cout<<r[n]<<'\n';
    }
    return 0;
}
