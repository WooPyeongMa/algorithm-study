//
//  2025-11-07_baekjoon_1406.cpp
//  algorithm
//
//  Created by 김채현 on 11/7/25.
//

#include <iostream>
#include <list>

using namespace std;

int main(void) {
    string str;
    int n;
    
    cin >> str >> n;
    
    list<char> li(str.begin(), str.end());
    
    auto cursor = li.end();
    
    while(n--) {
        string input;
        
        cin >> input;
        
        if(input[0] == 'P') {
            char input2;
            cin >> input2;
            li.insert(cursor, input2);
        }
        else if(input == "L") {
            if(cursor != li.begin()) cursor--;
        }
        else if(input == "D") {
            if(cursor != li.end()) cursor++;
        }
        else {
            if(cursor != li.begin()) cursor = li.erase(--cursor);
        }
    }
    
    for(char c: li) cout << c;
    
    return 0;
}
