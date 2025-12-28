#include<bits/stdc++.h>

using namespace std;
int gcd(int a,int b)
{
    if (b==0)
        return a;
    return gcd(b,a%b);
}
int solution(vector<int> arrayA, vector<int> arrayB) 
{
    
    int a=arrayA[0],b=arrayB[0];
    for(int i=1;i<arrayA.size();i++)
    {
        a=gcd(a,arrayA[i]);
        b=gcd(b,arrayB[i]);
    }
    bool bb=false,aa=false;
    for(int i=0;i<arrayB.size();i++)
    {
        if (!(arrayB[i]%a))
        {
            bb=true;break;
        }
    }
    for(int i=0;i<arrayA.size();i++)
    {
        if (!(arrayA[i]%b))
        {
            aa=true;break;
        }
    }
    //cout<<aa<<' '<<bb<<' '<<a<<' '<<b<<'\n';
    if (!aa&&!bb)
        return max(a,b);
    else if (!aa)
        return b;
    else if (!bb)
        return a;
    else 
        return 0;
    
}
