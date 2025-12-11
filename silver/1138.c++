#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<int>a(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
    {
        int stand=a[i],count=0;
        for (int k=0;k<n;k++)
        {
            if (!arr[k])
            {
                count++;
            }
            if (stand+1==count)
            {
                arr[k]=i+1;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<' ';
    cout<<'\n';
    return 0;
}
