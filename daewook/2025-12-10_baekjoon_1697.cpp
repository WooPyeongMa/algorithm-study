#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;
int arr[MAX + 1];
bool visited[MAX + 1];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visited[n] = true;
    arr[n] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == k) {
            cout << arr[x];
            return 0;
        }

        int dx[3] = {x - 1, x + 1, x * 2};

        for (int nxt : dx) {
            if (0 <= nxt && nxt <= MAX && !visited[nxt]) {
                visited[nxt] = true;
                arr[nxt] = arr[x] + 1;
                q.push(nxt);
            }
        }
    }
}