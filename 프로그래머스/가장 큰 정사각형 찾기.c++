#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    vector<vector<int>>arr(board.size(),vector<int>(board[0].size(),0));
    for(int i=0;i<board.size();i++)
    {
        arr[i][0]=(board[i][0])?1:0; 
    }
    for(int i=0;i<board[0].size();i++)
    {
        arr[0][i]=(board[0][i])?1:0;
    }
    for(int i=1;i<board.size();i++)
    {
        for(int k=1;k<board[i].size();k++)
        {
            arr[i][k]=board[i][k]?min({arr[i-1][k],arr[i-1][k-1],arr[i][k-1]})+1:0;
        }
    }
    for(int i=0;i<arr.size();i++)
    {
        for(int k=0;k<arr[i].size();k++)
        {
            answer=max(answer,arr[i][k]);
        }
    }
    return answer*answer;
}
