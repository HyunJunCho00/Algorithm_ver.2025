#include<bits/stdc++.h>
#define pp pair<int,double>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int,int>m;
    int size=stages.size();
    for(int i=0;i<stages.size();i++)
    {
        m[stages[i]]++;
    }
    vector<pp>a;
    for(int i=1;i<=N;i++)
    {
        int cnt=m[i];
        if (size)
            a.push_back({i,(double)cnt/size});
        else
            a.push_back({i,0.0});
        size-=cnt;
    }
    sort(a.begin(), a.end(), [](const pp& left, const pp& right) {
    if (left.second != right.second) {
        return left.second > right.second;
    }
    return left.first < right.first;
    });
    for(auto& aa:a)
    {
        answer.push_back(aa.first);
    }
    return answer;
}
