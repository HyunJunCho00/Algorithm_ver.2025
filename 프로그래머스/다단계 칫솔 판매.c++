#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    unordered_map<string,int>um;
    unordered_map<string,string>people;
    for(int i=0;i<enroll.size();i++)
    {
        people[enroll[i]]=referral[i];
    }
    for(int i=0;i<seller.size();i++)
    {
        string cur_name=seller[i];
        int total_price=amount[i]*100;
        while(1)
        {
            int cur_price=(int)total_price*0.1;
            if (cur_price>=1)
            {
                //cout<<cur_name<<' '<<total_price<<' '<<cur_price<<'\n';
                um[cur_name]+=total_price-cur_price;
            }
            else
            {
                um[cur_name]+=total_price;
            }
            total_price=cur_price;
            if (total_price==0)
                break;
            if (cur_name=="-")
                break;
            cur_name=people[cur_name];
        }
    }
    for(int i=0;i<enroll.size();i++)
    {
        answer.push_back(um[enroll[i]]);
    }
    return answer;
}
