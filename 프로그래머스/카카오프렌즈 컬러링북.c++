#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>>visited(m,vector<bool>(n,false));
    for(int i=0;i<m;i++)
    {
        for(int k=0;k<n;k++)
        {
            if(!visited[i][k]&&picture[i][k]!=0)
            {
                int standard=picture[i][k];
                number_of_area++;
                queue<pp>q;
                q.push({i,k});
                int max_count=1;
                visited[i][k]=true;
                while(!q.empty())
                {
                    pp p=q.front();
                    q.pop();
                    auto[x,y]=p;
                    for(int z=0;z<4;z++)
                    {
                        int nx=dx[z]+x,ny=dy[z]+y;
                        if(0<=nx&&nx<m&&0<=ny&&ny<n&&!visited[nx][ny]&&picture[nx][ny]==standard)
                        {
                            visited[nx][ny]=true;
                            q.push({nx,ny});
                            max_count++;
                        }
                    }
                }
                max_size_of_one_area=max(max_size_of_one_area,max_count);
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
