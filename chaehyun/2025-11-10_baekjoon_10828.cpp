//
//  2025-11-10_baekjoon_10828.cpp
//  algorithm
//
//  Created by 김채현 on 11/10/25.
//

#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

int main(void) {
    int n;
    
    cin >> n;
    
    while(n--) {
      string input;
      
      cin >> input;
      
        if(input == "push") {
            int value;
            cin >> value;
            st.push(value);
        }
        else if(input == "pop") {
            if(st.empty()) cout << -1 << endl;
            else {
                cout << st.top() << endl;
                st.pop();
            }
        }
        else if(input == "size") {
            cout << st.size() << endl;
        }
        else if(input == "empty") {
            if(st.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else {
            if(st.empty()) cout << -1 << endl;
            else cout << st.top() << endl;
        }
    }
    
    return 0;
}
