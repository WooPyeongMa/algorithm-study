//
//  2025-11-17_baekjoon_2493.cpp
//  algorithm
//
//  Created by 김채현 on 11/17/25.
//

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<pair<int, int>> st;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        int input;
        
        cin >> input;
        
        while(!st.empty()) {
            if(input > st.top().second) st.pop();
            else {
                cout << st.top().first << ' ';
                break;
            }
        }
        
        if(st.empty()) cout << "0 ";
        
        st.push(make_pair(i, input));
    }
    
    return 0;
}
