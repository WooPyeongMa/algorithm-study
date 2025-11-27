//
//  2025-11-26_baekjoon_10866.cpp
//  algorithm
//
//  Created by 김채현 on 11/26/25.
//

#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int main(void)
{
    int n;
    
    cin >> n;
  
    while(n--) {
        string str;
        
        cin >> str;
        
        if(str.substr(0, 10) == "push_front") {
            int input;
            cin >> input;
            dq.push_front(input);
        }
        else if(str.substr(0, 9) == "push_back") {
            int input;
            cin >> input;
            dq.push_back(input);
        }
        else if(str == "pop_front")
        {
            if(dq.empty()) cout << -1 << '\n';
            else
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if(str == "pop_back")
        {
            if(dq.empty()) cout << -1 << '\n';
            else
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if(str == "size") cout << dq.size() << '\n';
        else if(str == "empty")
        {
            if(dq.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(str == "front")
        {
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        }
        else
        {
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }

    return 0;
}
