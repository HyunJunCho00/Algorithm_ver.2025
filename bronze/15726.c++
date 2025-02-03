#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    long long int a,b,c;
    cin>>a>>b>>c;
    long long int s1=a*b/c>a*c/b?a*b/c:a*c/b;
    cout<<s1<<'\n';
    return 0;
}
