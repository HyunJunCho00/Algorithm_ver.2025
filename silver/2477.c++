#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int k;
    cin>>k;
    vector<vector<int>>arr(2,vector<int>(6,0));
    for(int i=0;i<6;i++)
    {
        cin>>arr[0][i]>>arr[1][i];
    }
    for(int i = 0; i < 6; i++)
    {
        bool ch = false;
        if ((arr[0][i] == 4 && arr[0][(i+1)%6] == 2 && arr[0][(i+2)%6] == 4 && arr[0][(i+3)%6] == 2) ||
            (arr[0][i] == 3 && arr[0][(i+1)%6] == 1 && arr[0][(i+2)%6] == 3 && arr[0][(i+3)%6] == 1) ||
            (arr[0][i] == 1 && arr[0][(i+1)%6] == 4 && arr[0][(i+2)%6] == 1 && arr[0][(i+3)%6] == 4) ||
            (arr[0][i] == 2 && arr[0][(i+1)%6] == 3 && arr[0][(i+2)%6] == 2 && arr[0][(i+3)%6] == 3)) 
        {
            ch = true;
        }
        
        if (ch)
        {
            int g = arr[1][i] + arr[1][(i+2)%6];
            int c = arr[1][(i+1)%6] + arr[1][(i+3)%6];

            cout << k * (g*c - arr[1][(i+1)%6] * arr[1][(i+2)%6]);
            break;
        } 
    }
    return 0;
}
