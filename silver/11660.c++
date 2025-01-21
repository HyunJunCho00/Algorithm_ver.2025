#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
vector <vector<int>>arr;
vector <vector<int>>sum;
int main(void)
{
    int n,m;
    cin>>n>>m;
    arr.assign(n+1,vector<int>(n+1,0));
    sum.assign(n+1,vector<int>(n+1,0));
    for (int i=1;i<=n;i++)
    {
        for (int k=1;k<=n;k++)
        {
            cin>>arr[i][k];
            sum[i][k]=sum[i-1][k]+sum[i][k-1]-sum[i-1][k-1]+arr[i][k];
        }
    }
    stringstream ss;
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ss << sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] << '\n';
    }
    cout << ss.str();
    return 0;
}
