#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string str;
    cin>>str;
    cout<<fixed<<setprecision(1);
    if (str.compare("A+")==0) cout<<4.3<<'\n';
    else if (str.compare("A0")==0) cout<<4.0<<'\n';
    else if (str.compare("A-")==0) cout<<3.7<<'\n';
    else if (str.compare("B+")==0) cout<<3.3<<'\n';
    else if (str.compare("B0")==0) cout<<3.0<<'\n';
    else if (str.compare("B-")==0) cout<<2.7<<'\n';
    else if (str.compare("C+")==0) cout<<2.3<<'\n';
    else if (str.compare("C0")==0) cout<<2.0<<'\n';
    else if (str.compare("C-")==0) cout<<1.7<<'\n';
    else if (str.compare("D+")==0) cout<<1.3<<'\n';
    else if (str.compare("D0")==0) cout<<1.0<<'\n';
    else if (str.compare("D-")==0) cout<<0.7<<'\n';
    else if (str.compare("F")==0) cout<<0.0<<'\n';
    return 0;
}
