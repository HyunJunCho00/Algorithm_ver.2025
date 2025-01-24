#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin>>t;
    queue <int> div;
    for (int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        while (n>0)
        {
            div.push(n%2);
            n/=2;
        }
        int idx=0;
        while (!div.empty())
        {
            int num=div.front();
            if (num)
                cout<<idx<<' ';
            div.pop();
            idx++;
        }
        cout<<'\n';
    }
    return 0;
}
