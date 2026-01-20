#include<bits/stdc++.h>
using namespace std;

string solution(int n, int t, int m, int p)
{
    string answer = "";
    string base="0123456789ABCDEF";
    int pp=0,tt=0;
    while(answer.length()<t)
    {
        string bb="";
        int ttt=tt;
        while(ttt)
        {
            bb+=base[ttt%n];
            ttt/=n;
        }

        for(int i=bb.length()-1;i>=0;i--)
        {
            if (pp==p-1&&answer.length()<t)
            {
                answer+=bb[i];
            }
            pp=(pp+1)%m;
        }
        if (!bb.length())
        {
            if (p-1==pp)
            {
                answer+="0";
            }
            pp=(pp+1)%m;
        }
    
        tt++;
    }
    return answer;
}
