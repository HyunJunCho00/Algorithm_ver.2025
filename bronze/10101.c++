#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b,c;
    cin>>a>>b>>c;
    if (a==b&&b==c&&a==c&&(a+b+c)==180)
        cout<<"Equilateral"<<'\n';
    else if ((a+b+c)!=180)
        cout<<"Error"<<'\n';
    else if (a!=b&&b!=c&&c!=a)
        cout<<"Scalene"<<'\n';
    else
        cout<<"Isosceles"<<'\n';
    return 0;
}
