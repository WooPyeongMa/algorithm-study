//
//  2025-12-01_baekjoon_3986.cpp
//  algorithm
//
//  Created by 김채현 on 12/1/25.
//

#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    int n, result = 0;
  
    cin >> n;
    
    while(n--) {
        string input;
        stack<char> st;
        
        cin >> input;
        
        for(char c: input) {
            if(st.empty()) st.push(c);
            else {
                if(st.top() == c) st.pop();
                else st.push(c);
            }
        }
        
        if(st.empty()) result++;
    }
    
    cout << result;
    
    return 0;
}
