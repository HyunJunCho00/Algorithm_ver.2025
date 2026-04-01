#include<bits/stdc++.h>
using namespace std;

int solution(vector<string> board) {

    int oo=0,xx=0;
    for(int k=0;k<board.size();k++)
    {
        for(int i=0;i<board.size();i++)
        {
            if (board[i][k]=='O')
                oo++;
            else if(board[i][k]=='X')
                xx++;
        }        
    }
    
    int o=0,x=0;
    for(int i=0;i<board.size();i++)
    {
        if (board[i][0]==board[i][1]&&board[i][1]==board[i][2])
        {
            if (board[i][0]=='O')o++;
            else if (board[i][0]=='X')x++;
        }
        if (board[0][i]==board[1][i]&&board[1][i]==board[2][i])
        {
            if (board[2][i]=='O')o++;
            else if (board[2][i]=='X')x++;
        }
    }
    if (board[0][0]==board[1][1]&&board[1][1]==board[2][2])
    {
            if (board[0][0]=='O')o++;
            else if (board[0][0]=='X')x++;
    }
    if (board[2][0]==board[1][1]&&board[1][1]==board[0][2])
    {
            if (board[1][1]=='O')o++;
            else if (board[1][1]=='X')x++;
    }
    
    if (oo<xx||oo-xx>1)return 0;
    
    if (o&&x) return 0;
    
    if (x&&oo!=xx) return 0;
    
    if (o&&oo!=xx+1) return 0;
    
    return 1;
}
