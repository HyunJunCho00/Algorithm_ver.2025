#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    set<int>left;
    set<int>right;
    unordered_map<int,int>m;
    for(int i=0;i<topping.size();i++)
    {
        m[topping[i]]++;
        right.insert(topping[i]);
    }
    for(int i=0;i<topping.size();i++)
    {
        int cur=topping[i];
        left.insert(cur);
        if (m[cur])
        {
            m[cur]--;
        }
        if (!m[cur])
        {
            right.erase(cur);
        }
        if (right.size()==left.size())
            answer++;
    }
    return answer;
}
