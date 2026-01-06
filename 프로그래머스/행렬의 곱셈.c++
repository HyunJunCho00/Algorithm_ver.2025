#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> answer(arr1.size(),vector<int>(arr2[0].size(),0));
    for(int i=0;i<arr1.size();i++)
    {
        for(int k=0;k<arr2[0].size();k++)
        {
            int s=0;
            for(int l=0;l<arr2.size();l++)
            {
                s+=arr1[i][l]*arr2[l][k];
            }
            answer[i][k]=s;
        }
    }
    return answer;
}
