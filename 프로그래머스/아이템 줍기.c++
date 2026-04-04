#include <bits/stdc++.h>
using namespace std;

int board[102][102]; // 2배 확대한 좌표계
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 1. 좌표 2배 확대 및 영역 표시
    for (auto& rect : rectangle) {
        int x1 = rect[0] * 2, y1 = rect[1] * 2;
        int x2 = rect[2] * 2, y2 = rect[3] * 2;

        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                // 이미 내부(2)로 판정된 곳이 아니라면 표시
                if (i > x1 && i < x2 && j > y1 && j < y2) {
                    board[i][j] = 2; // 내부는 2
                } else if (board[i][j] != 2) {
                    board[i][j] = 1; // 테두리는 1
                }
            }
        }
    }

    // 2. BFS 탐색
    queue<pair<pair<int, int>, int>> q;
    q.push({{characterX * 2, characterY * 2}, 0});
    vector<vector<bool>> vis(102, vector<bool>(102, false));
    vis[characterX * 2][characterY * 2] = true;

    while (!q.empty()) {
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if (curX == itemX * 2 && curY == itemY * 2) {
            return dist / 2; // 다시 2로 나누어 반환
        }

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            // 범위 내에 있고, 방문하지 않았으며, 테두리(1)인 경우만 이동
            if (nx >= 0 && nx <= 100 && ny >= 0 && ny <= 100) {
                if (board[nx][ny] == 1 && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({{nx, ny}, dist + 1});
                }
            }
        }
    }

    return 0;
}
