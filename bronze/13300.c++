#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,k;
    vector <vector <int>> arr;
    scanf("%d %d",&n,&k);
    arr.resize(7,vector <int>(2,0));
    for (int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        arr[b][a]++;
    }
    int room=0;
    for (int i=1;i<=6;i++)
    {
        for (int l=0;l<=1;l++)
        {
            int r=(arr[i][l]%k==0)?arr[i][l]/k:arr[i][l]/k+1;
            room+=r;
        }
    }
    printf("%d\n",room);
    return 0;
}
