#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int n, long long k) 
{
    vector<int> answer;
    vector<int>num;
    for(int i=1;i<=20;i++)
        num.push_back(i);
    vector<long long>factor(21,0);
    factor[0]=1;
    for(int i=1;i<=20;i++)
    {
        factor[i]=factor[i-1]*i;
    }
    k--;
    for(int i=n;i>=1;i--)
    {
        long long unit=factor[i-1];
        int index=k/unit;
        answer.push_back(num[index]);
        num.erase(num.begin()+index);
        k%=unit;
    }
    return answer;
}
