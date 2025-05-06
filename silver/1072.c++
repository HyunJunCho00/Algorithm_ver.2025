#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    long long int x,y;
    cin>>x>>y;
    long long int z=(100*y)/x;
    if (z>=99)
    {
        cout<<-1;exit(0);
    }
    long long int s=1,e=1000000000;
    long long int cnt=-1;
    while (s<=e)
    {
        long long int mid=(s+e)/2;
        long long int m=100*(y+mid)/(x+mid);
        (m>z)?(cnt=mid,e=mid-1):(s=mid+1);
    }
    cout<<cnt;
    return 0;
}
