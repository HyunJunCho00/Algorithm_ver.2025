#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> arr;
vector <vector <int>> save;
void solve(int n)
{

    save[0][0]=arr[0][0];
    save[1][0]=arr[1][0];
    if (n>=2)
    {
        save[0][1]=save[1][0]+arr[0][1];
        save[1][1]=save[0][0]+arr[1][1];
        for(int i=2;i<n;i++)
        {
            save[0][i]=max(arr[0][i]+save[1][i-1],arr[0][i]+save[1][i-2]);
            save[1][i]=max(arr[1][i]+save[0][i-1],arr[1][i]+save[0][i-2]);
        }
    }
    cout<<max(save[0][n-1],save[1][n-1])<<'\n';
}
int main(void)
{
    int t;
    cin>>t;
    for (int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        arr.assign(2,vector<int>(n,0));
        save.assign(2,vector<int>(n,0));
        for (int k=0;k<2;k++)
        {
            for (int l=0;l<n;l++)
            {
                cin>>arr[k][l];
            }
        }
        solve(n);
        arr.clear();
        save.clear();
    }
    return 0;
}
