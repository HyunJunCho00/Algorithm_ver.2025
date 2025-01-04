#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
vector <int> arr;
int main(void)
{
    arr.assign(5,0);
    int sum=0;
    for (int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    sort(arr.begin(),arr.end());
    printf("%d\n%d\n",sum/5,arr[2]);
    return 0;
}
