#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int>> arr;
vector <int> max_price;
int main(void){
    int n;
    cin>>n;
    int day,price;
    for (int i=0;i<n;i++)
    {
        scanf("%d %d",&day,&price);
        arr.push_back(make_pair(day,price));
    }
    max_price.assign(n+1,0);
    for (int i=0;i<n;i++)
    {
        max_price[i+1]=std::max(max_price[i+1],max_price[i]);
        if (i+arr[i].first<=n)
        {
            int idx=i+arr[i].first;
            max_price[idx]=std::max(max_price[idx],arr[i].second+max_price[i]);
        }

    }
    cout<<max_price[n]<<'\n';
    return 0;
}
