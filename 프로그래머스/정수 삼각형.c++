#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> triangle) 
{
    int h=triangle.size();
    for(int i=h-2;i>=0;i--)
    {
        for(int k=0;k<triangle[i].size();k++)
        {
            int left=triangle[i][k]+triangle[i+1][k];
            int right=triangle[i][k]+triangle[i+1][k+1];
            triangle[i][k]=max(left,right);
        }
    }
    return triangle[0][0];
}
