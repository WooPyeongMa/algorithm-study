//
//  2025-11-05_baekjoon_11328.cpp
//  algorithm
//
//  Created by 김채현 on 11/5/25.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    int n;
    
    cin >> n;
    
    while(n) {
        vector<int> v1(26);
        vector<int> v2(26);
        string str1, str2;
        int cnt = 0;
        
        cin >> str1 >> str2;
        
        for(int i = 0; str1[i] != '\0'; i++) v1[str1[i] - 'a']++;
        for(int i = 0; str2[i] != '\0'; i++) v2[str2[i] - 'a']++;
        
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i] != v2[i]) break;
            else cnt++;
        }
        
        if(cnt == 26) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
        
        n--;
    }
    
    return 0;
}
