//
//  2025-11-12_baekjoon_1874.cpp
//  algorithm
//
//  Created by 김채현 on 11/12/25.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> st;

int main(void) {
    int n, top = 0;
    string result = "";
    
    cin >> n;
    
    while(n--) {
        int input;
        
        cin >> input;
        
        if(st.empty() || st.top() < input) {
            for(int i = top + 1; i <= input; i++) {
                st.push(i);
                result += "+";
            }
            top = st.top();
        }
        if(st.top() == input) {
            st.pop();
            result += "-";
        }
        else if(st.top() > input) {
            result = "";
            break;
        }
    }
    
    if(result == "") cout << "NO";
    else for(char c: result) cout << c << "\n";
    
    return 0;
}
