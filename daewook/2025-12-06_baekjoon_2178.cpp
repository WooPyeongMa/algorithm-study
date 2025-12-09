#include <iostream>
#include <queue>

using namespace std;

int n, m;

int miro[100][100];
int visited[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({x, y});

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (!visited[nx][ny] && miro[nx][ny] == 1) {
                visited[nx][ny] = true;
                miro[nx][ny] = miro[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &miro[i][j]);
        }
    }

    bfs(0, 0);
    cout << miro[n - 1][m - 1];
    return 0;
}