#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) 
{
    int answer = 0;
    sort(data.begin(),data.end(),[col](vector<int>&a,vector<int>&b){
        if (a[col-1]!=b[col-1]) return a[col-1]<b[col-1];
        return a[0]>b[0];
    });
    for(int i=row_begin-1;i<=row_end-1;i++)
    {
        int res=0;
        for(int k=0;k<data[i].size();k++)
        {
            res+=data[i][k]%(i+1);
        }
        answer^=res;
    }
    return answer;
}
