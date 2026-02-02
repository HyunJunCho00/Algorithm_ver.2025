#include<bits/stdc++.h>
#define pp pair<int,int>
#define ppp pair<int,string>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,int>genSum;
    unordered_map<string,vector<pp>>song;
    for(int i=0;i<plays.size();i++)
    {
        song[genres[i]].push_back({plays[i],i});
        genSum[genres[i]]+=plays[i];
    }
    vector<ppp>order;
    for(auto&s:genSum)
    {
        order.push_back({s.second,s.first});
    }
    sort(order.begin(),order.end(),greater<>());
    for(auto&s:song)
    {
        sort(s.second.begin(),s.second.end(),[](auto&a,auto&b)
             {
                 if (a.first!=b.first) return a.first>b.first;
                 a.second>b.second;
             });
    }
    for(auto&o :order)
    {
        auto&v=song[o.second];
        for(int i=0;i<v.size()&&i<2;i++)
        {
            answer.push_back(v[i].second);
        }
    }
    return answer;
}
