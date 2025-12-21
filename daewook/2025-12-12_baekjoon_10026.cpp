#include <iostream>
#include <queue>

using namespace std;

int n;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char ground[100][100];
bool visited1[100][100];
bool visited2[100][100];

void bfs(int x, int y, char color) {
    queue<pair<int, int>> q1;
    visited1[x][y] = true;
    q1.push({x, y});

    while (!q1.empty()) {
        auto [nx, ny] = q1.front();
        q1.pop();

        for (int i = 0; i < 4; i++) {
            int cx = nx + dx[i];
            int cy = ny + dy[i];

            if (cx < 0 || cy < 0 || cx >= n || cy >= n)
                continue;

            if (!visited1[cx][cy] && ground[cx][cy] == color) {
                visited1[cx][cy] = true;
                q1.push({cx, cy});
            }
        }
    }
}

void bfs2(int x, int y, char color) {
    queue<pair<int, int>> q2;
    visited2[x][y] = true;
    q2.push({x, y});

    while (!q2.empty()) {
        auto [nx, ny] = q2.front();
        q2.pop();

        for (int i = 0; i < 4; i++) {
            int cx = nx + dx[i];
            int cy = ny + dy[i];

            if (cx < 0 || cy < 0 || cx >= n || cy >= n)
                continue;

            if (!visited2[cx][cy] && ground[cx][cy] == color) {
                visited2[cx][cy] = true;
                q2.push({cx, cy});
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ground[i][j];
        }
    }

    int n1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited1[i][j]) {
                bfs(i, j, ground[i][j]);
                n1++;
            }
        }
    }

    int n2 = 0;

    // 입력값 수정
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ground[i][j] == 'R')
                ground[i][j] = 'G';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited2[i][j]) {
                bfs2(i, j, ground[i][j]);
                n2++;
            }
        }
    }

cout << n1 << " " << n2;
return 0;
}