#include<bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    long long start=(long long)times[0];
    long long end=(long long)times[times.size()-1]*n;
    while (start<=end)
    {
        long long mid=(start+end)/2;
        long long sum=0;
        for(int i=0;i<times.size();i++)
        {
            sum+=mid/(long long)times[i];
        }
        if (sum<n)
        {
            start=mid+1;
        }
        else
        {
            if (answer)
                answer=min(answer,mid);
            else
                answer=mid;
            end=mid-1;
        }
    }
    return answer;
}
