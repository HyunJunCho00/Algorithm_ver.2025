#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int f=0,r=queue1.size();
    vector<int>qq;
    long long q1=0,q2=0;
    for(int i=0;i<queue1.size();i++)
    {
        qq.push_back(queue1[i]);
        q1+=queue1[i];
    }

    for(int i=0;i<queue2.size();i++)
    {
        qq.push_back(queue2[i]);    
        q2+=queue2[i];
    }

    int n=qq.size();
    while(1)
    {
        if (answer==n*4||f==r||(q1+q2)%2)
        {
            answer=-1;
            break;
        }
        if (q1==q2)
            break;
        if (q1<q2)
        {
            q1+=qq[r];
            q2-=qq[r];
            r=(r+1)%n;
        }
        else
        {
            q1-=qq[f];
            q2+=qq[f];
            f=(f+1)%n;
        }    
        answer++;
    }
    return answer;
}
