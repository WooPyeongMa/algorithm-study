#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    stack<pair<int, int>> s1;

    int n;
    cin >> n;

    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        while (!s1.empty() && s1.top().first < h)
            s1.pop();

        if (s1.empty())
            ans[i] = 0;

        else
            ans[i] = s1.top().second;

        s1.push({h, i + 1});
    }

    for (int a : ans)
        cout << a << " ";

    return 0;
}