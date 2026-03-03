#include<bits/stdc++.h>
using namespace std;

string solution(string s, string skip, int index) {
    string ans="";
    set<char>st;
    for(char ss:skip)
    {
        st.insert(ss);        
    }

    
    for(char &ch:s)
    {
        char c=ch;
        int i=0;
        while(i<index)
        {
            if (c=='z')
                c='a';
            else
                c=(char)(c+1);
            if (st.find(c)!=st.end())
                continue;
            i++;
        }
        ans+=c;
    }
    return ans;
}
