#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> dq;

    for (int i = 1; i < n + 1; i++)
        dq.push_back(i);

    while (dq.size() != 1) {
        dq.pop_front();

        if (dq.size() == 1) {
            cout << dq.front();
            return 0;
        }
        int tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
    }

    cout << dq.front();
    return 0;
}