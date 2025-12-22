#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> ingredient) 
{
    int answer = 0,i=0,size=ingredient.size();
    vector<int>s;
    for (int ind:ingredient)
    {
        s.push_back(ind);
        int n=s.size();
        if (n>=4)
        {
            if (s[n-4]==1&&s[n-3]==2&&s[n-2]==3&&s[n-1]==1)
            {
                for(int j=0;j<4;j++)s.pop_back();
                answer++;
            }
        }
    }
    return answer;
}
