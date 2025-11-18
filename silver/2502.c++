#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int d,k,a=1,b=1;
    cin>>d>>k;
    vector<int>fibo(d+1,0);
    fibo[2]=1;fibo[3]=1;
    for(int i=4;i<=d;i++)
        fibo[i]=fibo[i-1]+fibo[i-2];
    while(1)
    {
        if (fibo[d-1]*a+fibo[d]*b>k)
        {
            a+=1;b=1;
        }    
        else if (fibo[d-1]*a+fibo[d]*b==k&&a<=b)
            break;
        else 
            b+=1;
    }
    cout<<a<<'\n'<<b;
    return 0;
}
