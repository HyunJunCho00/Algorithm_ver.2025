#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define min(a,b) (((a)<(b))?(a):(b))
#define INF 10000000
int dp[1001][3];
int arr[1001][3];
void solved(int n)
{
    for (int i=0;i<n;i++)
    {
        scanf("%d %d %d",&dp[i][0],&dp[i][1],&dp[i][2]);
    }
    int ind[3][2]={{1,2},{0,2},{0,1}};
    int answer=INF;
    for (int k=0;k<3;k++)
    {
        for (int i=0;i<n;i++)
        {
            if (i==0)
            {
                for (int m=0;m<2;m++)
                {
                    arr[i][ind[k][m]]=INF;
                }
                arr[i][k]=dp[i][k];
            }
            else
            {
                for (int m=0;m<3;m++)
                {
                    arr[i][m]=min(dp[i][m]+arr[i-1][ind[m][0]],dp[i][m]+arr[i-1][ind[m][1]]);
                }
            }
        }
        if (answer==INF)
            answer=min(arr[n-1][ind[k][0]],arr[n-1][ind[k][1]]);
        else
        {
            int comp=min(arr[n-1][ind[k][0]],arr[n-1][ind[k][1]]);
            answer=min(comp,answer);
        }
    }
    cout<<answer<<'\n';
}
int main(void)
{
    int n;
    cin>>n;
    solved(n);
    return 0;
}
