#include<bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    int i=1;
    int s=(i-1)*i/2;
    while(s<=n)
    {
        //cout<<n<<' '<<s<<' '<<i<<' '<<answer<<'\n';
        if (!((n-s)%i))
        {
            answer+=1;
        }
        i+=1;
        s=(i+1)*i/2;
    }
    return answer;
}
