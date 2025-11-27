//
//  2025-11-27_baekjoon_1021.cpp
//  algorithm
//
//  Created by 김채현 on 11/27/25.
//

#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int main(void) {
    int n, count, result = 0;
    
    cin >> n >> count;
    
    for(int i = 1; i <= n; i++) dq.push_back(i);
    
    while(count--) {
        int target, index = 0;
        
        cin >> target;
        
        if(dq.front() == target) dq.pop_front();
        else {
            for(int i = 1; i < dq.size(); i++) {
                if(dq[i] == target) {
                    index = i;
                    break;
                }
            }
            
            if(index < dq.size() / 2) {
                while(dq.front() != target) {
                    int front = dq.front();
                    dq.push_back(front);
                    dq.pop_front();
                    result++;
                }
                dq.pop_front();
            }
            else {
                while(dq.front() != target) {
                    int back = dq.back();
                    dq.push_front(back);
                    dq.pop_back();
                    result++;
                }
                dq.pop_front();
            }
        }
    }
    
    cout << result;
    
    return 0;
}
