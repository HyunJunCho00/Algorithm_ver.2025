#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main(void)
{
    long long int f,t;
    cin>>f>>t;
    vector <long long int> arr;
    arr.assign(3,0);
    arr[0]=f,arr[1]=t,arr[2]=f-t;
    int count_5=0,count_2=0;
    for (int i=0;i<3;i++)
    {
        long long int two=2;
        long long int five=5;
        int cnt_5=0,cnt_2=0;
        while (arr[i]>=five||arr[i]>=two)
        {
            cnt_5+=arr[i]/five;
            cnt_2+=arr[i]/two;
            five*=5;two*=2;
        }
        if (i==0)
        {
            count_5+=cnt_5;
            count_2+=cnt_2;
        }
        else
        {
            count_5-=cnt_5;
            count_2-=cnt_2;
        }
    }
    cout<<min(count_5,count_2)<<'\n';
    return 0;
}
