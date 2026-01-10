#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) 
{
    vector<int> answer;
    for (int & ar:arr)
    {
        if (!(ar%divisor))
            answer.push_back(ar);
    }
    if (answer.size())
        sort(answer.begin(),answer.end());
    else
        answer.push_back(-1);
    return answer;
}
