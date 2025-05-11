#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    while(b!=0)
    {
        if (a>b)
        {
            int t=b;
            b=a%b;
            a=t;
        }
        else b=b%a;
    }
    return a;
}
int main(void)
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int new_a=a*d+b*c, new_b=b*d, gc=gcd(new_a,new_b);
    cout<<new_a/gc<<' '<<new_b/gc;
    return 0;
}
