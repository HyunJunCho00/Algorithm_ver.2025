#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,m,a_max=0;cin>>n;
    vector<int>a(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if (a_max<a[i])a_max=a[i];
    }
    cin>>m;
    int left=1,right=a_max,num=0;
    while(left<=right)
    {
        int mid=(left+right)/2;
        int cost=0;
        for(int aa:a)mid<=aa?cost+=mid:cost+=aa;
        if (cost>m)
        {
            right=mid-1;
        }
        else
        {
            num=max(num,mid);
            left=mid+1;
        }
    }
    cout<<num;
    return 0;
}
