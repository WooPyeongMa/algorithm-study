//
//  2025-12-03_baekjoon_10799.cpp
//  algorithm
//
//  Created by 김채현 on 12/3/25.
//

#include <iostream>
#include <stack>

using namespace std;

stack<char> st;

int main(void) {
    string input;
    int result = 0;
    
    cin >> input;
    
    for(int i = 0; i < input.size(); i++) {
        char c = input[i];
        if(c == '(') st.push(c);
        else {
            st.pop();
            if(input[i - 1] == '(') result += st.size();
            else result++;
        }
    }
    
    cout << result;
    
    return 0;
}
