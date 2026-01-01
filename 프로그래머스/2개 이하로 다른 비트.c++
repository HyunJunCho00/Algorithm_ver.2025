#include<bits/stdc++.h>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    
    vector<long long> answer;
    // 1번 풀이 방법
    // for(int i=0;i<numbers.size();i++)
    // {
    //     long long t=numbers[i];
    //     vector<int> two;
    //     if (!t)two.push_back(0);
    //     while(t)
    //     {
    //         two.push_back(t%2);
    //         t/=2;
    //     }
    //     two.push_back(0);
    //     for(int k=0;k<two.size();k++)
    //     {
    //         if (!two[k])
    //         {
    //             if (k==0)
    //             {
    //                 two[k]=1;
    //             }
    //             else
    //             {
    //                 two[k]=1;two[k-1]=0;
    //             }
    //             break;
    //         }
    //     }
    //     long long ans=0;
    //     long long tw=1;
    //     for(int k=0;k<two.size();k++)
    //     {
    //         ans+=two[k]*tw;
    //         tw*=2;
    //     }
    //     answer.push_back(ans);
    // }
    
    for (long long n:numbers)
    {
        long long bit=1;
        while(n&bit)
        {
            bit<<=1;
        }
        long long ans= n|bit;
        
        if (bit>1)
        {
            ans &= ~(bit>>1);
        }
        answer.push_back(ans);
    }
    
    return answer;
}
