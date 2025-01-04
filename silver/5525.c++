#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(void)
{
    deque<char>dq;
    int n,m;
    cin>>n>>m;
    cin.ignore();
    string str;
    getline(cin,str);
    int result=0;
    for (int i=0;i<str.length();i++)
    {
        if (str[i]=='I')
        {
            if (dq.empty()||dq.back()=='O')
                dq.push_back(str[i]); 
            else
            {
                dq.clear();dq.push_back(str[i]);
            }
            if (dq.size()==2*n+1)
            {
                for (int i=0;i<2;i++)
                    dq.pop_front();
                result++;
            }
        }
        else
        {
            if (!dq.empty()&&dq.back()=='I')
                dq.push_back(str[i]);
            else
                dq.clear();
        }
    }
    cout<<result<<'\n';
    return 0;
}
