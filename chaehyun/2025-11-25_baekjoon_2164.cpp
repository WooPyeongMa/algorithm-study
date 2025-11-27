//
//  2025-11-25_baekjoon_2164.cpp
//  algorithm
//
//  Created by 김채현 on 11/25/25.
//

#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main(void) {
    int n;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) q.push(i);
    
    while(q.size() != 1) {
        q.pop();
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    
    cout << q.front();
    
    return 0;
}
