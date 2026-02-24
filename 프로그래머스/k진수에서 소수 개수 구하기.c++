#include<bits/stdc++.h>
using namespace std;
bool isPrime(string ss)
{
    long long c=stoll(ss);
    if (c<2)
        return false;
    for(long long i=2;i<=sqrt(c);i++)
    {
        if ((c%i)==0)
            return false;
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string s="";
    while(n)
    {
        s+=to_string(n%k);
        n/=k;
    }
    reverse(s.begin(),s.end());
    string cur="";
    for(char c :s)
    {
        if (c=='0')
        {
            if (!cur.empty())
            {
                if (isPrime(cur))answer++;
                cur="";
            }
        }
        else
        {
            cur+=c;
        }
    }
    if (!cur.empty()&&isPrime(cur))answer++;
    
    return answer;
}
