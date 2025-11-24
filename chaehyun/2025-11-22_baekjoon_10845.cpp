//
//  2025-11-22_baekjoon_10845.cpp
//  algorithm
//
//  Created by 김채현 on 11/22/25.
//

#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main(void)
{
    int num;
    
    cin >> num;
    
    while(num--) {
        string str;
        
        cin >> str;
        
        if(str == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if(str == "pop") {
            if(q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(str == "size") cout << q.size() << '\n';
        else if(str == "empty") {
            if(q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(str == "front") {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }

    return 0;
}
