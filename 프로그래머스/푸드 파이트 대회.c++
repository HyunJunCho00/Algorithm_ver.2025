#include<bits/stdc++.h>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for(int i=1;i<food.size();i++)
    {
        if(food[i]%2)
            food[i]-=1;
        for(int k=0;k<food[i]/2;k++)
        {
            answer+=to_string(i);
        }
    }
    string rever=answer;
    reverse(rever.begin(),rever.end());
    answer+="0";
    answer+=rever;
    
    return answer;
}
