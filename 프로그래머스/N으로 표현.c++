#include<bits/stdc++.h>
using namespace std;

int solution(int N, int number) {

    vector<set<long long>> s(10);
    long long int n=N;
    for(int i=1;i<=9;i++)
    {
        s[i].insert(n);
        n=N+n*10;
    }
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<i;j++)
        {
            for(long long int op1:s[j])
            {
                for(long long int op2:s[i-j])
                {
                    s[i].insert(op1+op2);
                    s[i].insert(op1*op2);
                    s[i].insert(op1-op2);
                    if (op2)
                        s[i].insert(op1/op2);
                }
            }
        }
        if (s[i].find(number)!=s[i].end())
            return i;
    }
    return -1;
}
