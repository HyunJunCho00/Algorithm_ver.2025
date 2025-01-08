#include <bits/stdc++.h>
using namespace std;
vector <int> divv;
int main(void){
    int divide=0;
    while (1)
    {
            cin>>divide;
            if (divide==-1)
                break;
            divv.assign(divide,0);
            int idx=0;
            int sum=0;
            for (int k=1;k<divide;k++)
            {
                if (divide%k==0)
                {

                    sum+=k;
                    divv[idx++]=k;
                }
            }
            if (sum==divide)
            {
                cout<<divide<<" = "<<divv[0];
                for (int k=1;k<idx;k++)
                {
                    cout<<" + "<<divv[k];
                }
                cout<<'\n';              
            }
            else
                cout<<divide<<" is NOT perfect.\n";
    }   
    return 0;
}
