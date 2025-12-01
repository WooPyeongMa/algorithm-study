//
//  2025-11-28_baekjoon_5430.cpp
//  algorithm
//
//  Created by 김채현 on 11/28/25.
//

#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int tc;
    
    cin >> tc;
    
    while(tc--) {
        string p, arr, tmp = "";
        int n;
        bool err = 0, rev = 0;
        
        cin >> p >> n >> arr;
        
        deque<int> dq;
        
        if(n != 0) {
            for(int i = 1; i < arr.size() - 1; i++) {
              if(arr[i] != ',') tmp += arr[i];
              else {
                  dq.push_back(stoi(tmp));
                  tmp = "";
              }
            }
            dq.push_back(stoi(tmp));
        }
        
        for(char c: p) {
            if(c == 'R') rev = !rev;
            else {
                if(dq.empty()) {
                    cout << "error" << endl;
                    err = 1;
                    break;
                }
                else  {
                  if(rev) dq.pop_back();
                  else dq.pop_front();
                }
            }
        }
          
        if(err == false) {
            if(!dq.empty()) {
                if(rev) reverse(dq.begin(), dq.end());
                int i = 0;
                cout << "[";
                for(i = 0; i < dq.size() - 1; i++) cout << dq[i] << ",";
                cout << dq[i] << "]" << endl;
            }
            else cout << "[]" << endl;
        }
    }
    
    return 0;
}
