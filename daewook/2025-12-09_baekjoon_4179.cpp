#include <iostream>
#include <queue>

using namespace std;

int r, c;
char miro[1000][1000];
int jh[1000][1000];
int fire[1000][1000];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    cin >> r >> c;

    queue<pair<int, int>> q1; // 지훈
    queue<pair<int, int>> q2; // 불

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> miro[i][j];

            if (miro[i][j] == 'J') {
                q1.push({i, j});
                jh[i][j] = 1;
            }

            else if (miro[i][j] == 'F') {
                q2.push({i, j});
                fire[i][j] = 1;
            }
        }
    }

    // 불 bfs
    while (!q2.empty()) {
        auto [nx, ny] = q2.front();
        q2.pop();

        for (int i = 0; i < 4; i++) {
            int cx = nx + dx[i];
            int cy = ny + dy[i];

            if (cx < 0 || cy < 0 || cx >= r || cy >= c)
                continue;

            if (miro[cx][cy] != '#' && fire[cx][cy] == 0) {
                q2.push({cx, cy});
                fire[cx][cy] = fire[nx][ny] + 1;
            }
        }
    }

    // 지훈 bfs
    while (!q1.empty()) {
        auto [nx, ny] = q1.front();
        q1.pop();

        if (nx == 0 || ny == 0 || nx == r-1 || ny == c-1) {
            cout << jh[nx][ny];
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int cx = nx + dx[i];
            int cy = ny + dy[i];

            if (cx < 0 || cy < 0 || cx >= r || cy >= c)
                continue;

            if (miro[cx][cy] == '#' || jh[cx][cy])
                continue;

            if (fire[cx][cy] != 0 && fire[cx][cy] <= jh[nx][ny] + 1)
                continue;

            q1.push({cx, cy});
            jh[cx][cy] = jh[nx][ny] + 1;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}