#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    map<string,double> m;
    string s;
    double all=0;
    while(getline(cin,s))
    {
        m[s]++;all++;
    }
    cout<<fixed<<setprecision(4);
    for(auto iter=m.begin();iter!=m.end();iter++)
    {
        cout<<iter->first<<' '<<iter->second/all*100<<'\n';
    }
    return 0;
}
