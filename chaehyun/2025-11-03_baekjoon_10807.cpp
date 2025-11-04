//
//  2025-11-03_baekjoon_10807.c++
//  algorithm
//
//  Created by 김채현 on 11/03/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(void) {
    int n, target;
    int result = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    cin >> target;
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < n; i++){
        if(v[i] == target) result++;
    }
    
    cout << result;
    
    return 0;
}
