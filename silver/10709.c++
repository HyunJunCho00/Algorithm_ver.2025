#include <bits/stdc++.h>
using namespace std;
char arr[101][101];
int result[101][101];
int main()
{

    int h,w;
    scanf("%d %d",&h,&w);
    for (int i=0;i<h;i++)
        for (int k=0;k<w;k++)
            cin>>arr[i][k];
    for (int i=0;i<h;i++)
    {
        int k=0;
        while (k<w)
        {
            if (arr[i][k]=='c')
            {
                result[i][k]=0;
                while (arr[i][k+1]!='c'&&k<w)
                {
                    result[i][k+1]=result[i][k]+1;
                    k++;
                }
            }
            else
            {
                result[i][k]=-1;
            }
            k++;
        }
    }
    for (int i=0;i<h;i++)
    {
        for (int k=0;k<w;k++)
            printf("%d ",result[i][k]);
        printf("\n");
    }
    return 0;
}
