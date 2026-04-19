#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> stones, int k) 
{
    int answer=0;
    int left=0,right=200000000;
    
    while(left<=right)
    {
        int mid=(left+right)/2;
        bool check=true;
        int count=0;
        for(int stone:stones)
        {
            if (stone<mid)
            {
                count++;
                if (count>=k)
                {
                    check=false;
                    break;
                }
            }
            else
            {
                count=0;
            }
        }
        if (check)
        {
            answer=mid;
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return answer;
}
