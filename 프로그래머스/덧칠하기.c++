#include<bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<int> section) 
{
    int answer=0;
    int id=0,i=0;
    while(i<section.size())
    {
        id=(section[i]+m-1);
        while(i<section.size()&&id>=section[i])
            i++;
        answer++;
    }
    return answer;
}
