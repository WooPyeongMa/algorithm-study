//
//  2025-11-06_baekjoon_1919.cpp
//  algorithm
//
//  Created by 김채현 on 11/6/25.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> v1(26);
vector<int> v2(26);

int main(void) {
    string str1, str2;
    int cnt = 0;
    
    cin >> str1 >> str2;
    
    for(int i = 0; str1[i] != '\0'; i++) v1[str1[i] - 'a']++;
    for(int i = 0; str2[i] != '\0'; i++) v2[str2[i] - 'a']++;
    
    for(int i = 0; i < v1.size(); i++) {
        if(v1[i] != v2[i]) cnt += abs(v1[i] - v2[i]);
    }
    
    cout << cnt;
    
    return 0;
}
