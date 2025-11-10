#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;

    while (n--) {
        string op;
        cin >> op;

        if (op == "push") {
            int num;
            cin >> num;

            s.push(num);
        }

        else if (op == "pop") {
            if (s.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << s.top() << "\n";
            s.pop();
        }

        else if (op == "size") 
            cout << s.size() << "\n";
        
        else if (op == "empty") {
            if (s.empty())
                cout << 1 << "\n";
            
            else
                cout << 0 << "\n";
        }

        else if (op == "top") {
            if (s.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << s.top() << "\n";
        }
    }
    return 0;
}