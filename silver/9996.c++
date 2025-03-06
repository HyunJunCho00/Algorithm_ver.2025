#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;int n;cin>>n;
    string p,a;cin>>p;
    int sp=p.find('*');
    string pre=p.substr(0,sp),suf=p.substr(sp+1);
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if (a.length()<pre.length()+suf.length())
        {
            cout<<"NE\n";continue;
        }
        cout<<(a.substr(0,pre.length())==pre&&a.substr(a.length()-suf.length())==suf?"DA\n":"NE\n");

    }
    return 0;
}
