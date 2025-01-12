#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,m;
    cin>>n>>m;
    vector <bool> col_visited;
    vector <bool> row_visited;
    row_visited.assign(n,false);
    col_visited.assign(m,false);
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<m;k++)
        {
            char in;
            cin>>in;
            if (in=='X')
            {
                col_visited[i]=true;
                row_visited[k]=true;
            }
        }
    }
    int col_cnt=0,row_cnt=0;
    for (int i=0;i<n;i++)
    {
        if (col_visited[i]==false)
            col_cnt++;
    }
    for (int k=0;k<m;k++)
    {
        if (row_visited[k]==false)
            row_cnt++;
    }
    cout<<max(col_cnt,row_cnt)<<'\n';
    return 0;
}
