#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    vector<char> result;

    int cur = 1;

    while (n--) {
        int tar;
        cin >> tar;

        while (cur <= tar) {
            s.push(cur++);
            result.push_back('+');
        }

        if (s.top() == tar) {
            s.pop();
            result.push_back('-');
        }
        else {
            cout << "NO";
            return 0;
        }
    }

    for (char c : result)
        cout << c << "\n";

    return 0;
}