#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    while (1)
    {
        vector <int> t(3,0);
        cin>>t[0]>>t[1]>>t[2];
        sort(t.begin(),t.end());
        if (t[0]==0&&t[1]==0&&t[2]==0)
            break;
        if (t[0]==0||t[1]==0||t[2]==0)
            cout<<"Invalid"<<'\n';
        else if (t[0]==t[1]&&t[1]==t[2])
            cout<<"Equilateral"<<'\n';
        else if (t[0]==t[1]||t[1]==t[2])
        {
            if (t[0]+t[1]>t[2])
                cout<<"Isosceles"<<'\n';
            else
                cout<<"Invalid"<<'\n';
        }
        else if (t[0]+t[1]>t[2])
            cout<<"Scalene"<<'\n';
        else
            cout<<"Invalid"<<'\n';
    }
    return 0;
}
