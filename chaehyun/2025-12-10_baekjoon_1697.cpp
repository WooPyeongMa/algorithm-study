//
//  2025-12-10_baekjoon_1697.cpp
//  algorithm
//
//  Created by 김채현 on 12/10/25.
//

#include <iostream>
#include <queue>

#define MAX 100000

using namespace std;

queue<int> q;

int main(void) {
    int n, k;
    int dist[MAX + 1];
    
    cin >> n >> k;
    
    for(int i = 0; i <= MAX; i++) dist[i] = -1;
    
    dist[n] = 0;
    q.push(n);
    
    while(!q.empty()) {
        auto cur = q.front();
        int nx[3] = {cur - 1, cur + 1, cur * 2};
        
        q.pop();
        
        for(int i = 0; i < 3; i++) {
            int nt = dist[cur] + 1;
    
            if(nx[i] < 0 || nx[i] > MAX) continue;
            if(dist[nx[i]] != -1) continue;
            
            dist[nx[i]] = nt;
            q.push(nx[i]);
        }
    }
    
    cout << dist[k];
    
    return 0;
}
