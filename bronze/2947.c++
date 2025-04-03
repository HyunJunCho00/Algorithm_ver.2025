#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    vector<int>a(5);
    for(int i=0;i<5;i++)cin>>a[i];
    while(1)
    {
        bool ch=true;
        for(int i=0;i<4;i++)
        {
            if (a[i]>a[i+1])
            {
                ch=false;
                swap(a[i],a[i+1]);
                for(int k=0;k<5;k++)cout<<a[k]<<' ';
                cout<<'\n';
            }
        }
        if (ch)break;
    }
    return 0;
}
