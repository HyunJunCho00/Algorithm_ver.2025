#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<int>arr(n+1,0);
    for(int i=1;i<=n;i++)arr[i]=i;
    while (n>1)
    {
        vector<int>comp(1+n/2,0);
        int k=0;
        for(int i=2;i<=n;i+=2)
            comp[++k]=arr[i];
        arr=comp;n/=2;
    }
    cout<<arr[1]<<'\n';
    return 0;
}
///////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,i=1;cin>>n;
    while(i<n)i*=2;
    cout<<(i>n?i/2:i)<<'\n';
    return 0;
}
