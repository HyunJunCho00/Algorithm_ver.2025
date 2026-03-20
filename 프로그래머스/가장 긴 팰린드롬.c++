#include<bits/stdc++.h>
using namespace std;
int solution(string s)
{
    int answer=s.length();
    while(answer)
    {
        for(int i=0;i<=s.length()-answer;i++)
        {
            int left=i;
            int right=i+answer-1;
            while(left<right)
            {
                if (s[left]!=s[right])break;
                left++;right--;
            }
            if (left>=right)
                return answer;
            
        }
        answer--;
    }
    return answer;
}
