#include<bits/stdc++.h>
#define pp pair<string,int>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,vector<pp>>m;
    for(string record:records)
    {
        int h=stoi(record.substr(0,2));
        int mm=stoi(record.substr(3,2));
        string car=record.substr(6,4);
        string move=record.substr(11);
        m[car].push_back({move,h*60+mm});
    }
    for(const auto&mm:m)
    {
        int sum_time=0;
        string move="";
        int in_time=0;
        for(const auto&value:mm.second)
        {
            if (value.first=="IN")
            {
                move=value.first;
                in_time=value.second;
            }
            else
            {
                sum_time=sum_time+(value.second-in_time);
                in_time=0;
                move=value.first;
            }
        }
        if(move=="IN")
        {
            sum_time=sum_time+(23*60+59-in_time);
        }
        if (sum_time<=fees[0])
        {
            answer.push_back(fees[1]);
        }
        else
        {
            int add_time=sum_time-fees[0];
            add_time=(add_time%fees[2])?add_time/fees[2]+1:add_time/fees[2];
            int res=fees[1]+add_time*fees[3];
            answer.push_back(res);
        }
    }
    return answer;
}
