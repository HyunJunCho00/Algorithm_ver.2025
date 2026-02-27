#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int>s;
    for(int i=0;i<numbers.size()-1;i++)
    {
        for(int k=i+1;k<numbers.size();k++)
        {
            int c=numbers[i]+numbers[k];
            if (s.find(c)==s.end())
                s.insert(c);
        }
    }
    for(int i:s)
    {
        answer.push_back(i);
    }
    sort(answer.begin(),answer.end());
    return answer;
}
