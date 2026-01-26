#include<bits/stdc++.h>

using namespace std;
int dx[]={0,1,1};
int dy[]={1,0,1};
int solution(int m, int n, vector<string> board) 
{
    int answer = 0;
    while(1)
    {
        bool check=false;
        vector<vector<bool>>ch(m,vector<bool>(n,false));
        for(int i=0;i<m-1;i++)
        {
            for(int k=0;k<n-1;k++)
            {
                bool four=true;
                for(int l=0;l<3;l++)
                {
                    int nx=dx[l]+i,ny=dy[l]+k;
                    if (board[nx][ny]!=board[i][k]||board[i][k]=='.')
                    {
                        four=false;break;
                    }
                }
                if (four)
                {
                    ch[i][k]=true;
                    for(int l=0;l<3;l++)
                    {
                        int nx=dx[l]+i,ny=dy[l]+k;
                        ch[nx][ny]=true;
                    }
                    check=true;
                }
            }
        }
        if (!check)
            break;
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int k=0;k<m;k++)
            {
                if (board[k][i]!='.'&&!ch[k][i])temp+=board[k][i];
            }
            for(int k=0;k<m;k++)
            {
                if (k<m-temp.length())
                    board[k][i]='.';
                else
                    board[k][i]=temp[k-m+temp.length()];
            }
        }
        
    }
    for(int i=0;i<m;i++)
    {
        for(int k=0;k<n;k++)
        {
            if (board[i][k]=='.')answer++;
        }
    }
    return answer;
}
