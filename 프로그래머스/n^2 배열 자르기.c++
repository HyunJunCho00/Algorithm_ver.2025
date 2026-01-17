#include<bits/stdc++.h>

using namespace std;

vector<int> solution(int n, long long left, long long right) 
{ 
    vector<int> answer;
    while(left<=right)
    {
        long long l=left/n;
        long long div=left%n;
        for(int i=div;i<n&&left<=right;i++,left++)
        {
            if (!l)
            {
                answer.push_back(i+1);
            }
            else
            {
                if (i<=l)
                {
                    answer.push_back(l+1);
                }
                else
                {
                    answer.push_back(i+1);
                }
            }
        }
    }
    return answer;
}





#include<bits/stdc++.h>

using namespace std;

vector<int> solution(int n, long long left, long long right) 
{ 
    vector<int> answer;
    for(long long i=left;i<=right;i++)
    {
        long long r=i/n;
        long long c=i%n;
        answer.push_back(max(r,c)+1);
    }
    return answer;
}
