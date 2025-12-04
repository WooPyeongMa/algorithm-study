//
//  2025-12-04_baekjoon_2504.cpp
//  algorithm
//
//  Created by 김채현 on 12/4/25.
//

#include <iostream>
#include <stack>

using namespace std;

stack<char> st;

int main(void) {
    string input;
    int result = 0, tmp = 1;
    
    cin >> input;
    
    for(int i = 0; i < input.size(); i++) {
        char c = input[i];
        
        if(c == '(') {
            st.push(c);
            tmp *= 2;
        }
        else if(c == '[') {
            st.push(c);
            tmp *= 3;
        }
        else if(c == ')') {
            if(!st.empty() && st.top() == '(') {
                st.pop();
                if(input[i - 1] == '(') result += tmp;
                tmp /= 2;
            }
            else {
                result = 0;
                break;
            }
        }
        else {
            if(!st.empty() && st.top() == '[') {
                st.pop();
                if(input[i - 1] == '[') result += tmp;
                tmp /= 3;
            }
            else {
                result = 0;
                break;
            }
        }
    }
    
    if(!st.empty()) result = 0;
    
    cout << result;
    
    return 0;
}
