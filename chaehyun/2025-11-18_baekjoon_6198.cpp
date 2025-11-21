//
//  2025-11-18_baekjoon_6198.cpp
//  algorithm
//
//  Created by 김채현 on 11/18/25.
//

#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

int main(void) {
    int n;
    long long result = 0;
    
    cin >> n;
    
    while(n--) {
        int input;
        
        cin >> input;
        
        if(st.empty()) {
            st.push(input);
            continue;
        }
        
        while(!st.empty() && input >= st.top()) st.pop();
        
        result += st.size();
        
        st.push(input);
    }
    
    cout << result;
    
    return 0;
}
