#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int s=0,e=0,climb=0;
    while(1)
    {
        if (a[s]<a[e]){
            
            while(s<n&&e<n&&a[s]<a[e])
            {
                if (e>=1&&a[e]>a[e-1])
                    e++;
                else break;
            }
            climb=max(climb,a[e-1]-a[s]);
            s=e;
            if (e==n)break;
        }
        else{
            if (e==n-1){
                break;
            }
            else{
                if (s<e)s++;
                else e++;
            }
        }
    }
    cout<<climb;
    return 0;
}
