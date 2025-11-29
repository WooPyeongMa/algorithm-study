//
//  2025-11-29_baekjoon_4949.cpp
//  algorithm
//
//  Created by 김채현 on 11/29/25.
//

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    while(1) {
        stack<char> s;
        string input;
        bool err = false;
        
        getline(cin, input);
        
        if(input == ".") break;
        
        for(char c: input) {
            if(c == '(' || c == '[') s.push(c);
            else if(c == ')') {
                if(!s.empty() && s.top() == '(') s.pop();
                else {
                    err = true;
                    break;
                }
            }
            else if(c == ']') {
                if(!s.empty() && s.top() == '[') s.pop();
                else {
                    err = true;
                    break;
                }
            }
        }
        
        if(err == false && s.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    
    return 0;
}
