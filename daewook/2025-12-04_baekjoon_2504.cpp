#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string word;
    cin >> word;

    int result = 0;
    int temp = 1;
    stack<char> st;

    for (int i = 0; i < word.size(); i++) {
        if (word[i] == '(') {
            st.push('(');
            temp *= 2;
        }

        else if (word[i] == '[') {
            st.push('[');
            temp *= 3;
        }

        else if (word[i] == ')') {
            if (st.empty() || st.top() != '(') {
                result = 0;
                break;
            }

            if (word[i-1] == '(')
                result += temp;

            st.pop();
            temp /= 2;
        }

        else if (word[i] == ']') {
            if (st.empty() || st.top() != '[') {
                result = 0;
                break;
            }

            if (word[i-1] == '[')
                result += temp;

            st.pop();
            temp /= 3;
        }
    }

    if (!st.empty())
        result = 0;

    cout << result;
    return 0;
}