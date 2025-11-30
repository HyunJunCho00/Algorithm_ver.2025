#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int a,b,c,d=0;
    set<int>aa;
    cin>>a>>b;
    for(int i=0;i<a;i++)
    {
        cin>>c;
        aa.insert(c);
    }
    for(int i=0;i<b;i++)
    {
        cin>>c;
        aa.find(c)!=aa.end()?aa.erase(c):d+=1;
    }
    cout<<aa.size()+d;
    return 0;
}
