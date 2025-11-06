//
//  2025-10-30_baekjoon_10808.c++
//  algorithm
//
//  Created by 김채현 on 10/31/25.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> v(26);

int main(void) {
    string str;
    
    cin >> str;
    
    for(int i = 0; i < str.size(); i++) v[str[i] - 'a']++;
    
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    
    return 0;
}
