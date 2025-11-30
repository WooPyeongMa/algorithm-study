#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {

        if (line == ".") break;

        string word;

        for (char c : line) {
            if (c == '(' || c == ')' || c == '[' || c == ']' || c == '.')
                word += c;
        }

        stack<char> st;
        bool result = true;

        for (int i = 0; i < word.size(); i++) {

            if (word[i] == '(')
                st.push('(');
            
            else if (word[i] == '[')
                st.push('[');

            else if (word[i] == ']' && !st.empty() && st.top() == '[')
                st.pop();

            else if (word[i] == ')' && !st.empty() && st.top() == '(')
                st.pop();

            else if (word[i] == '.') 
                break;
            
            else {
                result = false;
                break;
            }
        }
        if (!st.empty())
            result = false;

        cout << (result ? "yes\n" : "no\n");
    }

    return 0;
}