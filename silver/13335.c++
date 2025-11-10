#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,w,l;
    cin>>n>>w>>l;
    deque<int>car;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        car.push_back(a);
    }
    vector<int>arr(w,0);
    int time=0,wei=0;
    while(1)
    {
        if (!time)
        {
            int s=car.front();
            car.pop_front();
            arr[0]=s;
            wei=s;
        }
        else
        {
            if (arr[w-1])
            {
                wei-=arr[w-1];
            }
            for(int i=w-2;i>=0;i--)
            {
                arr[i+1]=arr[i];
            }
            arr[0]=0;
            int s=car.front();
            if (wei+s<=l)
            {
                car.pop_front();
                arr[0]=s;
                wei+=s;
            }
        }
        time++;
        if (car.empty())
        {
            for(int i=0;i<w;i++)
            {
                if (arr[i])
                {
                    time+=w-i;
                    break;
                }
            }
            break;
        }
    }
    cout<<time;
    return 0;
}
