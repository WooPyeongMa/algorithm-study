#include <iostream>
#include <queue>

using namespace std;

int n, m;
int picture[500][500];
bool visited[500][500];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int area = 1;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (!visited[nx][ny] && picture[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                area++;
            }
        }
    }
    return area;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> picture[i][j];
        }
    }

    int cnt = 0;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && picture[i][j] == 1) {
                cnt++;
                int area = bfs(i, j);
                maxArea = max(maxArea, area);
            }
        }
    }

    cout << cnt << "\n";
    cout << maxArea;
}