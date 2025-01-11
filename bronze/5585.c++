#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin>>n;
    n=1000-n;
    int count=0;
    vector <int>arr;
    arr.assign(6,0);
    arr[0]=500;arr[1]=100;arr[2]=50;arr[3]=10;arr[4]=5;arr[5]=1;
    for (int i=0;i<6;i++)
    {
        count+=n/arr[i];
        n%=arr[i];
    }
    cout<<count<<'\n';
    return 0;
}
