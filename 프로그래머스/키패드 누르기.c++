#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    map<int,pp>m;
    int n=1;
    for(int i=0;i<3;i++)
    {
        for(int k=0;k<3;k++)
        {
            m[n++]={i,k};
        }
    }
    m[0]={3,1};
    int left_x=3,left_y=0;
    int right_x=3,right_y=2;
    for(int nn:numbers)
    {
        pp p=m[nn];
        int left_com=abs(left_x-p.first)+abs(left_y-p.second);
        int right_com=abs(right_x-p.first)+abs(right_y-p.second);
        if (nn==1||nn==4||nn==7)
        {
            answer+='L';
            left_x=p.first;left_y=p.second;
        }
        else if (nn==3||nn==6||nn==9)
        {
            answer+='R';
            right_x=p.first;right_y=p.second;
        }
        else
        {
            if (left_com!=right_com)
            {
                if (left_com>right_com)
                {
                    answer+='R';
                    right_x=p.first;right_y=p.second;
                }
                else
                {
                    answer+='L';
                    left_x=p.first;left_y=p.second;
                }
            }      
            else if (hand=="left")
            {
                answer+='L';
                left_x=p.first;left_y=p.second;
            }
            else
            {
                answer+='R';
                right_x=p.first;right_y=p.second;
            }
        }
    }
    return answer;
}
