#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,k;
    cin>>n>>k;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int mm;cin>>mm;
        arr.push_back(mm);
    }
    int s=0;
    map<int,int> m;
    int maxLen=0;
    for(int e=0;e<arr.size();e++)
    {
       m[arr[e]]++;
       while (m[arr[e]]>k)
       {
            m[arr[s]]--;
            s++;
       }
       maxLen=max(maxLen,e-s+1);
    }
    cout<<maxLen;
    return 0;
}
