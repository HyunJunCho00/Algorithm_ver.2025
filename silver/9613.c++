#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
vector <int> arr;
int gcd(int a,int b)
{
    int tmp,n;
    if (a<b)
    {
        tmp=a;
        a=b;
        b=tmp;
    }
    while (b!=0)
    {
        n=a%b;
        a=b;
        b=n;  
    }
    return a;
}
void solve(int n)
{
    long long int sum=0;
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
            sum+=gcd(arr[i],arr[j]);
    }
    cout<<sum<<'\n';
}
int main(void)
{
    fastIO;
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        int n;
        cin>>n;
        arr.assign(n,0);
        for (int k=0;k<n;k++)
            cin>>arr[k];
        solve(n);
    }
    return 0;
}
