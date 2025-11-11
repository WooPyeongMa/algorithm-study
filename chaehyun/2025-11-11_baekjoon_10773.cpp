//
//  2025-11-11_baekjoon_10773.cpp
//  algorithm
//
//  Created by 김채현 on 11/11/25.
//

#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

int main(void) {
    int k, sum = 0;
    
    cin >> k;
    
    while(k--) {
        int input;
        
        cin >> input;
        
        if(input == 0) st.pop();
        else st.push(input);
    }
    
    while(!st.empty()) {
        sum += st.top();
        st.pop();
    }
    
    cout << sum;
    
    return 0;
}
