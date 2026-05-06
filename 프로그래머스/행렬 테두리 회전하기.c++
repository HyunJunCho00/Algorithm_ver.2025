#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>>copy(rows+1,vector<int>(columns+1,0));
    int start=1;
    for(int i=1;i<=rows;i++)
    {
        for(int k=1;k<=columns;k++)
        {
            copy[i][k]=start++;
        }
    }

    for(int i=0;i<queries.size();i++)
    {
        int x1=queries[i][0],y1=queries[i][1],x2=queries[i][2],y2=queries[i][3];    
        vector<vector<int>>arr=copy;
        int min_value=10001;
        for(int k=y1+1;k<=y2;k++)
        {
            copy[x1][k]=arr[x1][k-1];
            min_value=min(min_value,copy[x1][k]);
        }
        for(int k=x1+1;k<=x2;k++)
        {
            copy[k][y2]=arr[k-1][y2];
            min_value=min(min_value,copy[k][y2]);
        }
        for(int k=y2-1;k>=y1;k--)
        {
            copy[x2][k]=arr[x2][k+1];
            min_value=min(min_value,copy[x2][k]);
        }
        for(int k=x2-1;k>=x1;k--)
        {
            copy[k][y1]=arr[k+1][y1];
            min_value=min(min_value,copy[k][y1]);
        }
        answer.push_back(min_value);
    }
    return answer;
}
