#include<bits/stdc++.h>
using namespace std;
#define INF 99999999
int main(void)
{
    int n;cin>>n;
    vector<vector<int>>arr(n+1,vector<int>(n+1,INF));

    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
            char s;cin>>s;
            if (i==k)
                arr[i][k]=0;
            if (s=='Y')
                arr[i][k]=1;
        }
    }

    for(int k=1;k<=n;k++) 
    {
        for(int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++) 
            {
                if (arr[i][k] != INF && arr[k][j] != INF) {
                    arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
                }
            }
        }
    } 
    int max_f=0;
    for(int i=1;i<=n;i++)
    {
        int c_f=0;
        for(int k=1;k<=n;k++)
        {
            if (arr[i][k]==1||arr[i][k]==2)
                c_f++;
        }
        max_f=max(max_f,c_f);
    }
    cout<<max_f;
    return 0;
}
