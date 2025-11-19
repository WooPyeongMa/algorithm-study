#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v(n);
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        while (!st.empty() && st.top().first < a) {
            v[st.top().second] = a;
            st.pop();
        }

        st.push({a, i});
    }

    while (!st.empty()) {
        v[st.top().second] = -1;
        st.pop();
    }

    for (int i : v)
        cout << i << " ";

    return 0;
}