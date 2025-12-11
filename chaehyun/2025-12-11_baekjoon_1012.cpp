//
//  2025-12-11_baekjoon_1012.cpp
//  algorithm
//
//  Created by 김채현 on 12/11/25.
//

#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int t;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    cin >> t;
    
    while(t--) {
        int m, n, k, result=0;
        int farm[50][50];
        bool visited[50][50];
        
        cin >> m >> n >> k;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                farm[i][j] = 0;
                visited[i][j] = false;
            }
        }
        
        while(k--) {
            int x, y;
            cin >> x >> y;
            farm[x][y] = 1;
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(farm[i][j] == 1 && !visited[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while(!q.empty()) {
                        auto cur = q.front();
                        q.pop();
                        
                        for(int i = 0; i < 4; i++) {
                            int nx = cur.first + dx[i];
                            int ny = cur.second + dy[i];
                            
                            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                            if(visited[nx][ny]) continue;
                            if(farm[nx][ny] == 0) continue;
                            
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                    
                    result++;
                }
            }
        }
        
        cout << result << endl;
    }
    
    return 0;
}
