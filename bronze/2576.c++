#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int b;vector<int>a;
    for (int i=0;i<7;i++)
    {
        cin>>b;if(b%2) a.push_back(b);
    }
    sort(a.begin(),a.end());
    if (a.size())
        cout<<(int)accumulate(a.begin(),a.end(),0)<<'\n'<<*a.begin()<<'\n';
    else
        cout<<-1<<'\n';
    return 0;
}
