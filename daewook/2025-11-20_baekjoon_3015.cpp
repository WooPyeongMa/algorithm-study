#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<pair<int, int>> st;
    long long result = 0;

    while (n--) {
        int m;
        cin >> m;

        while (!st.empty() && st.top().first < m) {
            result += st.top().second;
            st.pop();
        }

        if (!st.empty() && st.top().first == m) {
            if (st.size() > 1)
                result++;
                
            result += st.top().second;
            st.top().second++;
            continue;
        }

        if (!st.empty() && st.top().first > m) {
            result++;
        }

        st.push({m, 1});
    }

    cout << result;

    return 0;
}