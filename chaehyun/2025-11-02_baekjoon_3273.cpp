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

vector<int> v;

int main(void) {
    int n, sum;
    int left=0, right=0;
    int result = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    cin >> sum;
    
    sort(v.begin(), v.end());
    
    right = n - 1;
    while(left < right){
        if(v[left] + v[right] == sum){
            left++;
            right--;
            result++;
        }
        else if(v[left] + v[right] < sum) left++;
        else right--;
    }
    
    cout << result;
    
    return 0;
}
