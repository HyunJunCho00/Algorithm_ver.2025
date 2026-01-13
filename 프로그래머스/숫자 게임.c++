#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) 
{
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end());
    int f=0,b=B.size();
    for(int a:A)
    {
        if (a>=B[b-1])
        {
            f++;
        }
        else
        {
            b--;
        }
    }

    return B.size()-f;
}
