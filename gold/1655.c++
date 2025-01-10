#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(void)
{
    int n;
    cin>>n;
    int num;
    priority_queue <int,vector<int>,greater<int>> min_heap;
    priority_queue <int> max_heap;
    for (int i=0;i<n;i++)
    {
        cin>>num;
        int max_top,min_top;
        if (max_heap.size())
            max_top=max_heap.top();
        if (min_heap.size())
            min_top=min_heap.top();
        if (i%2==0)
        {
            if (max_heap.size()==0||min_top>=num)
            {
                max_heap.push(num);
            }
            else
            {
                min_heap.push(num);
                max_heap.push(min_top);
                min_heap.pop();
            }
        }
        else
        {
             if (max_heap.size()<min_heap.size())
             {
                if (min_top<num)
                {
                    min_heap.pop();
                    max_heap.push(min_top);
                    min_heap.push(num);
                }
                else
                {
                    max_heap.push(num);
                }
             }
             else
             {
                if (max_top>num)
                {
                    max_heap.pop();
                    min_heap.push(max_top);
                    max_heap.push(num);
                }
                else
                {
                    min_heap.push(num);
                }
             } 
        }
        std::cout<<max_heap.top()<<'\n';
    }
    return 0;
}
