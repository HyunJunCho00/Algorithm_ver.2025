#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
char arr[3100][6200];
void counting(int x,int y,int n)
{
    if (n==3)
    {
        arr[x][y]='*';
        arr[x+1][y-1]='*';
        arr[x+1][y+1]='*';
        for (int i=y-2;i<=y+2;i++)
            arr[x+2][i]='*';
        return;
    }
    else
    {
        counting(x,y,n/2);
        counting(x+n/2,y-n/2,n/2);
        counting(x+n/2,y+n/2,n/2);
    }
}
int main(void)
{
    fastIO;
    int n;
    cin>>n;
    counting(0,n-1,n);
    for (int i=0;i<n;i++){
        for (int j=0;j<2*n-1;j++)
        {
            if (arr[i][j]=='*')
                cout<<arr[i][j];
            else
                cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
