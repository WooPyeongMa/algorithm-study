//
//  2025-11-30_baekjoon_11003.cpp
//  algorithm
//
//  Created by 김채현 on 11/30/25.
//

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<pair<int, int>> dq;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, L;
    
    cin >> N >> L;
    
    for(int i = 0; i < N; i++) {
        int input;
        
        cin >> input;
        
        while(!dq.empty() && dq.front().second < i - L + 1) dq.pop_front();
        
        while(!dq.empty() && dq.back().first > input) dq.pop_back();
        
        dq.push_back({input, i});
        
        cout << dq.front().first << " ";
    }
    
    return 0;
}
