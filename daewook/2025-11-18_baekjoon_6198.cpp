#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s1;
    long long result = 0;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        while (!s1.empty() && s1.top() <= h)
            s1.pop();

        result += s1.size();

        s1.push(h);
    }

    cout << result;

    return 0;
}