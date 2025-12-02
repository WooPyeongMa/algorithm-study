//
//  2025-12-02_baekjoon_9012.cpp
//  algorithm
//
//  Created by 김채현 on 12/2/25.
//

#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    int n;
    
    cin >> n;
    
    while(n--) {
        string input;
        stack<char> st;
        bool err = false;
        
        cin >> input;
        
        for(char c: input) {
            if(c == '(') st.push(c);
            else {
                if(st.top() == ')') st.pop();
                else if(st.empty()) err = true;
            }
        }
        
        if(st.empty() && err == false) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
