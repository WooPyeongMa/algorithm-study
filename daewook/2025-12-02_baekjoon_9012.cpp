#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string ps;
        cin >> ps;

        stack<char> st;
        bool check = true;

        for (int i = 0; i < ps.size(); i++) {
            if (ps[i] == '(')
                st.push('(');

            else if (!st.empty() && st.top() == '(')
                st.pop();

            else
                check = false;
        }

        if (st.empty() && check)
            cout << "YES\n";

        else
            cout << "NO\n";
    }

    return 0;
}