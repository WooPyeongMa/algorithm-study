//
//  2025-11-04_baekjoon_13300.c++
//  algorithm
//
//  Created by 김채현 on 11/04/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> man(6);
vector<int> woman(6);

int main(void) {
    int n, k;
    int result = 0;
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int gender, grade;
        cin >> gender >> grade;
        if(gender == 0) woman[grade - 1]++;
        else man[grade - 1]++;
    }
    
    for(int i = 0; i < 6; i++) {
        result += woman[i] / k;
        result += man[i] / k;
        if(woman[i] % k != 0) result++;
        if(man[i] % k != 0) result++;
    }
    
    cout << result;
    
    return 0;
}
