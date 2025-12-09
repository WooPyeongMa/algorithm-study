//
//  2025-12-08_baekjoon_7576.cpp
//  algorithm
//
//  Created by 김채현 on 12/8/25.
//

#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;

int main(void) {
    int m, n, result=0;
    int box[1000][1000];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    cin >> m >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> box[i][j];
            if(box[i][j] == 1) q.push(make_pair(i, j));
        }
    }
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(box[nx][ny] != 0) continue;
            
            box[nx][ny] = box[cur.first][cur.second] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(box[i][j] == 0) {
                cout << -1;
                return 0;
            }
            if(box[i][j] > result) result = box[i][j];
        }
    }
    
    cout << result - 1;
    
    return 0;
}
