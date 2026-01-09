#include<bits/stdc++.h>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(n,0);
    answer[0]=x;
    for(int i=1;i<n;i++)
    {
        answer[i]=answer[i-1]+answer[0];
    }
    return answer;
}
