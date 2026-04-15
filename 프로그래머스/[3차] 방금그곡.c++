#include<bits/stdc++.h>

using namespace std;
string convert(string m)
{
    string res="";
    for(int i=0;i<m.length();i++)
    {
        if (i+1<m.length()&&m[i+1]=='#')
        {
            res+=tolower(m[i]);
            i++;
        }
        else res+=m[i];
    }
    return res;
}
string solution(string mm, vector<string> musicinfos) {
    string answer = "(None)";
    string m=convert(mm);
    
    int max_durations=0;
    for(string ms:musicinfos)
    {
        stringstream ss(ms);
        vector<string>save;
        string s;
        while(getline(ss,s,','))
            save.push_back(s);
        int before=stoi(save[0].substr(0,2))*60+stoi(save[0].substr(3,2));
        int after=stoi(save[1].substr(0,2))*60+stoi(save[1].substr(3,2));
        int diff=after-before;
        save[3]=convert(save[3]);
        string change="";
        int idx=0;
        for(int i=0;i<diff;i++)
        {
            change+=save[3][(idx%save[3].length())];
            idx++;
        }
        save[3]=change;
        if (save[3].find(m)!=save[3].npos)
        {
            if (diff>max_durations)
            {
                max_durations=diff;
                answer=save[2];
            }
        }
    }
    return answer;
}
