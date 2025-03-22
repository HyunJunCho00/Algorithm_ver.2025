#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;
    string s;
    vector<vector<char>>arr(3,vector<char>(3));
    while(1)
    {
        cin>>s;
        if(s=="end")break;
        int xx=0,y=0;
        for(int k=0;k<9;k++)
        {
            arr[xx][y]=s[k];
            (y+1==3)?(y=0,xx++):y++;
        }
        bool ch=true;
        int x=0,o=0,blank=0;
        for(int i=0;i<3;i++)
        {
            for(int k=0;k<3;k++)
            {
                if (arr[i][k]=='X')x++;
                else if (arr[i][k]=='O')o++;
                else blank++;
            }
        }
        if (blank==0)
        {
            int x3=0,o3=0;
            for(int i=0;i<3;i++)
            {
                if (arr[i][0]=='X'&&arr[i][1]=='X'&&arr[i][2]=='X')x3++;
                if (arr[i][0]=='O'&&arr[i][1]=='O'&&arr[i][2]=='O')o3++;
                if (arr[0][i]=='X'&&arr[1][i]=='X'&&arr[2][i]=='X')x3++;
                if (arr[0][i]=='O'&&arr[1][i]=='O'&&arr[2][i]=='O')o3++;
            }
            if (arr[0][0]=='X'&&arr[1][1]=='X'&&arr[2][2]=='X')x3++;
            if (arr[0][0]=='O'&&arr[1][1]=='O'&&arr[2][2]=='O')o3++;
            if (arr[2][0]=='X'&&arr[1][1]=='X'&&arr[0][2]=='X')x3++;
            if (arr[2][0]=='O'&&arr[1][1]=='O'&&arr[0][2]=='O')o3++;
            x==o+1?(x3<=1&&o3==1?ch=false:ch=true):ch=false;
        }
        else
        {
            int x3=0,o3=0;
            for(int i=0;i<3;i++)
            {
                if (arr[i][0]=='X'&&arr[i][1]=='X'&&arr[i][2]=='X')x3++;
                if (arr[i][0]=='O'&&arr[i][1]=='O'&&arr[i][2]=='O')o3++;
                if (arr[0][i]=='X'&&arr[1][i]=='X'&&arr[2][i]=='X')x3++;
                if (arr[0][i]=='O'&&arr[1][i]=='O'&&arr[2][i]=='O')o3++;
            }
            if (arr[0][0]=='X'&&arr[1][1]=='X'&&arr[2][2]=='X')x3++;
            if (arr[0][0]=='O'&&arr[1][1]=='O'&&arr[2][2]=='O')o3++;
            if (arr[2][0]=='X'&&arr[1][1]=='X'&&arr[0][2]=='X')x3++;
            if (arr[2][0]=='O'&&arr[1][1]=='O'&&arr[0][2]=='O')o3++;
            (blank%2)?(o3==1&&x3==0&&x==o?ch=true:ch=false):(o3==0&&x3==1&&x==o+1)?ch=true:ch=false;
        }
        cout<<(ch?"valid\n":"invalid\n");
    }
    return 0;
}
