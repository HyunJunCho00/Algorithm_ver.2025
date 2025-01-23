#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int l,a,b,c,d;
    cin>>l>>a>>b>>c>>d;
    cout<<l-max(a%c?1+a/c:a/c,b%d?1+b/d:b/d)<<'\n';
    return 0;
}
