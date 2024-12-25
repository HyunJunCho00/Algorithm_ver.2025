#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
using namespace std;

int main(void)
{

    char input;
    int t,test,value;
    cin>>t;
    for (int i=0;i<t;i++)
    {
        priority_queue<int,vector<int>,greater<int>> min_pq;
        priority_queue<int> max_pq;
        unordered_map<int,int> map;
        cin>>test;
        for (int k=0;k<test;k++)
        {
            getchar();
            scanf("%c %d",&input,&value);
            if (input=='D')
            {
                if (value==1)
                {
                   while (!max_pq.empty() && map[max_pq.top()] == 0) {
                        max_pq.pop();
                    }
                    if (!max_pq.empty()) {
                        map[max_pq.top()]--;
                        max_pq.pop();
                    }
                }
                else if (value==-1)
                {
                    while (!min_pq.empty() && map[min_pq.top()] == 0) {
                        min_pq.pop();
                    }
                    if (!min_pq.empty()) {
                        map[min_pq.top()]--;
                        min_pq.pop();
                    }
                }
            }
            else
            {
                max_pq.push(value);
                min_pq.push(value);
                map[value]++;
            }
        }
        while (!max_pq.empty() && map[max_pq.top()] == 0) {
            max_pq.pop();
        }
        while (!min_pq.empty() && map[min_pq.top()] == 0) {
            min_pq.pop();
        }
        if (max_pq.empty()||min_pq.empty())
            cout<<"EMPTY\n";

        else
            cout<<max_pq.top()<<" "<<min_pq.top()<<"\n";
    }
    return 0;
}
