#include <iostream>
#include <queue>

using namespace std;

int m, n, h;

// 가로 x 세로 x 높이
int tomato[100][100][100];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

struct Tomato {
    int x, y, z, day;
};

queue<Tomato> q;

int bfs() {
    int maxDay = 0;

    while (!q.empty()) {
        auto [nx, ny, nz, day] = q.front();
        q.pop();

        maxDay = max(maxDay, day);

        for (int i = 0; i < 6; i++) {
            int cx = nx + dx[i];
            int cy = ny + dy[i];
            int cz = nz + dz[i];

            if (cx < 0 || cy < 0 || cz < 0 || cx >=m || cy >= n || cz >= h)
                continue;

            if (tomato[cx][cy][cz] == 0) {
                tomato[cx][cy][cz] = 1;
                q.push({cx, cy, cz, day + 1});
            }
        }
    }

    return maxDay;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> h;

    // 초기 tomato 값 채우기
    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                cin >> tomato[x][y][z];

                if (tomato[x][y][z] == 1)
                    q.push({x, y, z, 0});
            }
        }
    }

    int days = bfs();

    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (tomato[x][y][z] == 0) {
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << days << "\n";
    return 0;
}