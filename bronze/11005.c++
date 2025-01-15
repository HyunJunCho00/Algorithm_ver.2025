#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,b;
    cin>>n>>b;
    vector <int>arr;
    while (1)
    {
        if (n==0)
            break;
        arr.push_back(n%b);
        n/=b;
    }
    while (!arr.empty())
    {
        int pop=arr.back();
        if (pop>=10)
        {
            char z='A'+pop-10;
            cout<<z;
        }
        else
            cout<<pop;
        arr.pop_back();
    }
    cout<<'\n';
    return 0;
}
