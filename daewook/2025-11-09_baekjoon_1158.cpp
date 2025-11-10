#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q;

    for (int i = 0; i < n; i++)
        q.push(i + 1);

    cout << '<';

    while (!q.empty()) {
        for (int i = 0; i < k - 1; i++) {
            int tmp;
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        if (q.size() == 1) {
            cout << q.front();
            q.pop();
            continue;
        }
        cout << q.front() << ", ";
        q.pop();
    }

    cout << '>';
    return 0;
}
