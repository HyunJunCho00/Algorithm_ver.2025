#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,c=0;cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        int s=0,e=n-1; bool ch=false;
        while(s<e)
        {
            if (s==i||e==i)
            {
                s==i?s++:e--;
                continue;
            }
            int com=arr[s]+arr[e];
            com>arr[i]?e--:(com==arr[i])?(ch=true,s++):s++;
            if (ch)break;
        }
        ch?c++:c=c;
    }
    cout<<c<<'\n';
    return 0;
}
