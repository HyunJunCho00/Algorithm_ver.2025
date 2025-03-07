#include<bits/stdc++.h>
#define tu tuple<string,int,int,int>
using namespace std;
int main(void)
{
    int n;cin>>n;
    vector<tu>arr;
    for(int i=0;i<n;i++)
    {
        string s;int d,m,y;
        cin>>s>>d>>m>>y;
        arr.push_back({s,d,m,y});
    }
    sort(arr.begin(),arr.end(),[](const auto&a,const auto&b){
        if (get<3>(a)==get<3>(b))
        {
            if(get<2>(a)==get<2>(b))
                return get<1>(a)>get<1>(b);
            return get<2>(a)>get<2>(b);
        }
        return get<3>(a)>get<3>(b);
    });
    cout<<get<0>(arr[0])<<'\n'<<get<0>(arr[n-1])<<'\n';
    return 0;
}
