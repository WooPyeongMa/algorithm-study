#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string s1;
    cin >> s1;

    stack<char> st;

    int result = 0;

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '(')
            st.push('(');

        else {
            st.pop();
            if (s1[i-1] == '(')
                result += st.size();
            else
                result++;
        }
    }
    cout << result;

    return 0;
}