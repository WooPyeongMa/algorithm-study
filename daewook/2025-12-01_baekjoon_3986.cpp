#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int n, result = 0;
    cin >> n;

    while (n--) {
        stack<char> st;

        string word;
        cin >> word;

        for (int i = 0; i < word.size(); i++) {
            if (!st.empty() && word[i] == st.top())
                st.pop();

            else
                st.push(word[i]);
        }

        if (st.empty())
            result++;
    }

    cout << result;
    return 0;
}