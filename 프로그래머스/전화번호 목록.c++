#include<bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string,int>m;
    for(int i=0;i<phone_book.size();i++)
    {
        for(int k=1;k<phone_book[i].size();k++)
        {
            if (m.count(phone_book[i].substr(0,k)))
                answer=false;
        }
        m[phone_book[i]]=1;
    }
    
    return answer;
}
