#include <iostream>
#include <queue>
using namespace std;

int m, n; // m = 가로(X), n = 세로(Y)
int baechu[50][50];
bool visited[50][50];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y) {  // x = 열, y = 행
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            if (baechu[ny][nx] == 1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> m >> n >> k;

        // 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                baechu[i][j] = 0;
                visited[i][j] = false;
            }
        }

        // 배추 위치 입력
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;  
            baechu[y][x] = 1; // 중요!!
        }

        int worm = 0;

        // 모든 좌표 탐색
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (baechu[y][x] == 1 && !visited[y][x]) {
                    bfs(x, y);
                    worm++;
                }
            }
        }

        cout << worm << "\n";
    }
}
