//
//  2025-11-07_baekjoon_5397.cpp
//  algorithm
//
//  Created by 김채현 on 11/8/25.
//

#include <iostream>
#include <list>

using namespace std;

int main(void) {
    int n;
    
    cin >> n;
    
    while(n--) {
        string input;
        list<char> li;
        auto cursor = li.begin();
        
        cin >> input;
        
        for(char c: input) {
            if(c == '-') {
                if(cursor != li.begin()) cursor = li.erase(--cursor);
            }
            else if(c == '<') {
                if(cursor != li.begin()) cursor--;
            }
            else if(c == '>') {
                if(cursor != li.end()) cursor++;
            }
            else li.insert(cursor, c);
        }
        
        for(char c: li) cout << c;
        cout << endl;
    }
    
    return 0;
}
