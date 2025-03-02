#include<bits/stdc++.h>
#define fastIO ios:: sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(void)
{
    fastIO;string s,t;
    while (cin>>s>>t)
    {
        int i=0,e=0;
        while(i<s.length()&&e<t.length())
        {
            s[i]==t[e]?(i++,e++):e++;
        }
        cout<<(i==s.length()?"Yes\n":"No\n");
    }
    return 0;
}
