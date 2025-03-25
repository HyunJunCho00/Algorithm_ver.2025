#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    while(b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main(void)
{
    int n,m;cin>>n>>m;
    vector<int>div;
    for (int i=1;i<=sqrt(m/n);i++)
    {
        if ((m/n)%i==0)
        {
            div.push_back(i);
            if (i*i!=(m/n))
                div.push_back((m/n)/i);
        }
    }
    int a=1000000000,b=1000000000,s=2000000000;
    if (div.size()%2==0)
    {
        for(int i=0;i<div.size();i+=2)
        {
            int c_a=div[i],c_b=div[i+1];
            gcd(c_a,c_b)==1&&s>c_a*n+c_b*n?(s=c_a*n+c_b*n,a=c_a*n,b=c_b*n):s=s;
        }
        cout<<a<<' '<<b;
    }
    else cout<<n<<' '<<m;
    return 0;
}
