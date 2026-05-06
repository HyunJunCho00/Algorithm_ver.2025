#include<bits/stdc++.h>

using namespace std;
vector<int> answer(2,0);
vector<int>sale;
void dfs(vector<vector<int>>&users, vector<int>&emoticons,int depth,vector<int>&save)
{
    if(emoticons.size()==depth)
    {
        vector<int>temp(2,0);
        for(int k=0;k<users.size();k++)
        {
            int price=0;
            for(int z=0;z<emoticons.size();z++)
            {
                if(users[k][0]<=sale[z])
                {
                    price+=(emoticons[z]/100*(100-sale[z]));  
                }
            }
            if(price>=users[k][1])
            {
                temp[0]++;
            }
            else
            {
                temp[1]+=price;
            }
        }
        if(answer[0]<temp[0])
        {
            answer=temp;
        }
        else if (answer[0]==temp[0]&&answer[1]<temp[1])
        {
            answer=temp;
        }
        return;
    }
    
    for(int k=0;k<4;k++)
    {
        sale.push_back(save[k]);
        dfs(users,emoticons,depth+1,save);
        sale.pop_back();
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int>sale(4,0);
    for(int i=1;i<=4;i++)
        sale[i-1]=i*10;
    dfs(users,emoticons,0,sale);
    return answer;
}
