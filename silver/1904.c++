#include <bits/stdc++.h>
using namespace std;
vector <int>arr;
int main(void)
{
    int n;
    cin>>n;
    arr.assign(n+1,0);
    arr[1]=1;
    arr[2]=2;
    for (int i=3;i<=n;i++)
    {
        arr[i]=(arr[i-1]+arr[i-2])%15746;
    }
    cout<<arr[n]<<'\n';
    return 0;
}
