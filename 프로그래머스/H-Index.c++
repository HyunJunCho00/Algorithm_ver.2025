#include<bits/stdc++.h>

using namespace std;
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    for(int i=0;i<=citations[citations.size()-1];i++)
    {
        auto it = lower_bound(citations.begin(), citations.end(), i);
        int count=citations.end()-it;
        if (count>=i&&citations.size()-count<=i)
            answer=i;
    }
    return answer;
}
