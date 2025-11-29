#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n, m, rotate = 0;
    cin >> n;

    deque<int> dq;

    for (int i = 1; i < n + 1; i++)
        dq.push_back(i);

    cin >> m;

    while (m--) {
        int wanted;
        cin >> wanted;

        // 찾고자 하는 값의 위치 찾기
        deque<int>::iterator it = find(dq.begin(), dq.end(), wanted);
        int index = distance(dq.begin(), it);

        if (index <= (dq.size() / 2)) {
            // 2번 수행
            for (int i = 0; i < index; i++) {
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
                rotate++;
            }
        }

        else {
            // 3번 수행
            for (int i = 0; i < dq.size() - index; i++) {
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
                rotate++;
            }
        }

        dq.pop_front();
    }

    cout << rotate;

    return 0;
}