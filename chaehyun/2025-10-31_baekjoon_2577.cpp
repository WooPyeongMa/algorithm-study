//
//  2025-10-30_baekjoon_10808.c++
//  algorithm
//
//  Created by 김채현 on 10/31/25.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> v(10);

int main(void) {
    int a, b, c;
    int result = 0;
    
    cin >> a >> b >> c;
    
    result = a * b * c;
    
    while(result > 0) {
        v[result % 10]++;
        result /= 10;
    }
    
    for(int i = 0; i < v.size(); i++) cout << v[i] << '\n';
    
    return 0;
}
