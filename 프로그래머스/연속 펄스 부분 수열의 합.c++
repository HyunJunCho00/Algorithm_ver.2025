#include<bits/stdc++.h>
using namespace std;

long long solution(vector<int> sequence) {
    vector<long long>seq(sequence.size()+1,0);
    for(int i=0;i<sequence.size();i++)
    {
        if (i%2)
        {
            seq[i+1]=seq[i]-sequence[i];
        }
        else
        {
            seq[i+1]=seq[i]+sequence[i];
        }
    }
    auto max_val=*max_element(seq.begin(),seq.end());
    auto min_val=*min_element(seq.begin(),seq.end());
    return max_val-min_val;
}
