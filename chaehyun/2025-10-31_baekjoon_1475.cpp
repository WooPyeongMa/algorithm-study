//
//  2025-10-30_baekjoon_10808.c++
//  algorithm
//
//  Created by 김채현 on 10/31/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(10);

int main(void) {
    int n;
    int sum;
    vector<int>::iterator maxPtr;

    cin >> n;
    
    while(n > 0) {
        v[n % 10]++;
        n /= 10;
    }
    
    sum = v[6] + v[9];
    if(sum % 2 == 0){
        v[6] = sum / 2;
        v[9] = sum / 2;
    }
    else{
        v[6] = sum / 2 + 1;
        v[9] = sum / 2 + 1;
    }
    
    maxPtr = max_element(v.begin(), v.end());
    
    cout << *maxPtr;
    
    return 0;
}
