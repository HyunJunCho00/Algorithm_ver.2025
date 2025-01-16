#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    vector <int> arr;
    arr.assign(3,0);
    for (int i=0;i<3;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    for (int i=0;i<3;i++)
        cout<<arr[i]<<' ';
    cout<<'\n';
    return 0;
}
