#include<bits/stdc++.h>

using namespace std;

long long solution(long long n) 
{
    long long answer=0;
    vector<int>arr(10,0);
    while(n)
    {
        int c=n%10;
        arr[c]++;
        n/=10;
    }
    long long i=1;
    for(int k=0;k<10;k++)
    {
        while(arr[k])
        {
            answer+=i*k;
            arr[k]--;
            i*=10;
        }
    }
    return answer;
}
