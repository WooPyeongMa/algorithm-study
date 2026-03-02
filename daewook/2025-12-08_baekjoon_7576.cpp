#include <iostream>
#include <queue>

using namespace std;

struct Tomato {
    int x, y, day;
};

int n, m;

int tomato[1000][1000];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {

    cin >> m >> n;
    queue<Tomato> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];

            if (tomato[i][j] == 1)
                q.push({i, j, 0});
        }
    }

    int maxDay = 0;

    while (!q.empty()) {

        auto [cx, cy, day] = q.front();
        q.pop();

        maxDay = max(maxDay, day);

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (tomato[nx][ny] != 0)
                continue;

            tomato[nx][ny] = 1;
            q.push({nx, ny, day + 1});
            
        }
    }
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << maxDay;
    return 0;
}