#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int arr[2][2];
int main(void)
{
    fastIO;
    int c,f;
    cin>>arr[0][0]>>arr[0][1]>>c>>arr[1][0]>>arr[1][1]>>f;
    int det= arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
    int x = (c * arr[1][1] - arr[0][1] * f) / det;
    int y = (arr[0][0] * f - c * arr[1][0]) / det;
    cout<<x<<' '<<y<<'\n';
    return 0;
}
