#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // testcase 개수
    int t;
    cin >> t;

    while (t--) {
        // dq 방향
        char dir = 'F';

        // 명령어 모음
        string op;
        cin >> op;

        // 데이터 개수
        int n;
        cin >> n;

        // 데이터 받기
        deque<int> dq;

        string s;
        cin >> s;

        if (n > 0) {
            s = s.substr(1, s.size() - 2);
            stringstream ss(s);
            string temp;

            while (getline(ss, temp, ',')) {
                dq.push_back(stoi(temp));
            }
        }

        bool err = false;

        // 결과 탐색
        for (int i = 0; i < op.size(); i++) {
            // drop 일 때,
            if (!dq.empty() && op[i] == 'D') {
                if (dir == 'F')
                    dq.pop_front();
                else
                    dq.pop_back();
            }

            else if (dq.empty() && op[i] == 'D') {
                err = true;
                break;
            }

            // rotate 일 때,
            else if (!dq.empty() && op[i] == 'R') {
                if (dir == 'F')
                    dir = 'B';
                else
                    dir = 'F';
            }
        }

        if (err == true)
            cout << "error\n";

        else {

            int dq_size = dq.size();

            cout << '[';
            for (int i = 0; i < dq_size; i++) {
                if (dir == 'F') {
                    cout << dq.front();
                    dq.pop_front();
                }
                else if (dir == 'B') {
                    cout << dq.back();
                    dq.pop_back();
                }

                if (!(i+1 == dq_size))
                    cout << ",";
            }
            cout << "]\n";
        }
    }
}