#include <bits/stdc++.h>
using namespace std;
vector <vector<int>> dp;
int main(void)
{
    int n;
    cin>>n;
    int count=0;
    dp.resize(n,vector<int>(10,1));
    dp[0][0]=0;
    for (int i=1;i<n;i++)
    {
        for (int k=0;k<=9;k++)
        {
            if (k==0)
            {
                dp[i][k]=(dp[i-1][k+1])%1000000000;
            }
            else if (k==9)
            {
                dp[i][k]=(dp[i-1][k-1])%1000000000;   
            }
            else
            {
                dp[i][k]=(dp[i-1][k+1]+dp[i-1][k-1])%1000000000;   
            }
        }
    }
    for (int i=0;i<=9;i++)
        count=(count+dp[n-1][i])%1000000000;
    cout<<count<<'\n';
    return 0;
}
