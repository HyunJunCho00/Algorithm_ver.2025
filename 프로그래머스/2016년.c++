#include<bits/stdc++.h>
using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string>day;
    day.push_back("SUN");
    day.push_back("MON");
    day.push_back("TUE");
    day.push_back("WED");
    day.push_back("THU");
    day.push_back("FRI");
    day.push_back("SAT");
    int sdd=5;
    int days=0;
    for(int i=1;i<a;i++)
    {
        if (i==1||i==3||i==5||i==7||i==8||i==10||i==12)
            days+=31;
        else if (i==2)
            days+=29;
        else
            days+=30;
    }
    days+=b-1;
    answer=day[(days+sdd)%7];
    return answer;
}
